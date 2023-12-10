FROM debian:bookworm-slim

# Set the code working directory
ARG CODE_PATH=/opt/code
WORKDIR ${CODE_PATH}
ENV HOME=${CODE_PATH}

# Install prerequisites
ENV DEBIAN_FRONTEND noninteractive
RUN \
  apt-get update && \
  apt-get upgrade -y && \
  apt-get install -y \
    apt-transport-https \
    apt-utils \
    ca-certificates \
    git \
    gnupg \
    minicom \
    python3 \
    python3-pip \
    screen \
    software-properties-common \
    wget \
    zsh \
    && \
  apt-get install -y \
    autoconf \
    automake \
    build-essential \
    cmake \
    gcc-arm-none-eabi \
    gdb-multiarch \
    libftdi-dev  \
    libnewlib-arm-none-eabi \
    libtool \
    libusb-1.0-0-dev \
    openocd \
    pkg-config \
    texinfo \
    && \
  apt-get clean && \
  rm -rf /var/lib/apt/lists/* && \
  chsh -s /bin/zsh && \
  git config --global advice.detachedHead false && \
  git config --global user.name "Phillip DuLion" && \
  git config --global user.email "phillip@dulion.com"

RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.5/zsh-in-docker.sh)" -- \
    -p git

# Install Pico SDK
ARG SDK_PATH=${CODE_PATH}/pico_sdk
RUN \
  git clone --depth 1 --branch 1.5.1 https://github.com/raspberrypi/pico-sdk.git ${SDK_PATH} && \
  cd ${SDK_PATH} && \
  git submodule update --init

ENV PICO_SDK_PATH=${SDK_PATH}
ENV PICO_EXAMPLES_PATH=${CODE_PATH}/pico_examples
ENV PICO_EXTRAS_PATH=${CODE_PATH}/pico_extras
ENV PICO_PLAYGROUND_PATH=${CODE_PATH}/pico_playground
RUN \
  git clone --depth 1 --branch sdk-1.5.1 --recurse-submodules https://github.com/raspberrypi/pico-examples.git   ${PICO_EXAMPLES_PATH} && \
  git clone --depth 1 --branch sdk-1.5.1 --recurse-submodules https://github.com/raspberrypi/pico-extras.git     ${PICO_EXTRAS_PATH}   && \
  git clone --depth 1 --branch sdk-1.5.1 --recurse-submodules https://github.com/raspberrypi/pico-playground.git ${PICO_PLAYGROUND_PATH}

# Build Pico Examples
ARG PICO_EXAMPLES_BUILD=${PICO_EXAMPLES_PATH}/build
RUN \
  cmake -S ${PICO_EXAMPLES_PATH} -B ${PICO_EXAMPLES_BUILD} -DCMAKE_BUILD_TYPE=Debug && \
  cd ${PICO_EXAMPLES_BUILD} && \
  make -j4

# Install OpenOCD
ARG PICO_OPENOCD_PATH=${CODE_PATH}/openocd
RUN \
  git clone --depth 1 --branch rp2040-v0.12.0 --recurse-submodules https://github.com/raspberrypi/openocd.git ${PICO_OPENOCD_PATH} && \
  cd ${PICO_OPENOCD_PATH} && \
  ./bootstrap && \
  ./configure --enable-ftdi --enable-sysfsgpio --enable-bcm2835gpio --enable-picoprobe && \
  make -j4 && \
  make install

# Install Pico Tool
ARG PICOTOOL_PATH=${CODE_PATH}/picotool
ARG PICOTOOL_BUILD=${PICOTOOL_PATH}/build
RUN \
  git clone --depth 1 --branch 1.1.2 https://github.com/raspberrypi/picotool.git ${PICOTOOL_PATH} && \
  cmake -S ${PICOTOOL_PATH} -B ${PICOTOOL_BUILD} && \
  cd ${PICOTOOL_BUILD} && \
  make -j4 && \
  cp ${PICOTOOL_BUILD}/picotool /bin/picotool && \
  rm -rf ${PICOTOOL_PATH}

# Install FreeRTOS
RUN \
  git clone --depth 1 --branch V10.6.1 https://github.com/FreeRTOS/FreeRTOS-Kernel.git && \
  git clone --depth 1 --branch V4.0.0  https://github.com/FreeRTOS/FreeRTOS-Plus-TCP.git && \
  git clone --depth 1 --branch v1.2.0  https://github.com/FreeRTOS/coreMQTT-Agent.git && \
  git clone --depth 1 --branch v2.1.1  https://github.com/FreeRTOS/coreMQTT.git && \
  git clone --depth 1 --branch v3.0.0  https://github.com/FreeRTOS/coreHTTP.git && \
  git clone --depth 1 --branch v3.5.0  https://github.com/FreeRTOS/corePKCS11.git && \
  git clone --depth 1 --branch v3.2.0  https://github.com/FreeRTOS/coreJSON.git && \
  git clone --depth 1 --branch v1.2.0  https://github.com/FreeRTOS/coreSNTP.git

ENV FREERTOS_KERNEL_PATH=${CODE_PATH}/FreeRTOS-Kernel

COPY --chmod=700 ./entrypoint /root/
ENTRYPOINT ["/root/entrypoint"]

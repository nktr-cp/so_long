FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    clang \
    make \
    vim \
    imagemagick \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    xorg \
    libxext-dev \
    x11-apps \
    zlib1g-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y \
    libxrandr-dev \
    libxinerama-dev \
    libxi-dev \
    libxcursor-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app
RUN rm -rf /app/mlx

RUN git clone https://github.com/42Paris/minilibx-linux.git mlx_temp && \
    mkdir -p mlx && \
    cp -r mlx_temp/* mlx/ && \
    rm -rf mlx_temp && \
    cd mlx && \
    make

COPY ./entrypoint.sh /usr/local/bin/entrypoint.sh

RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

CMD ["/bin/bash"]


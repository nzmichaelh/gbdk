# Build gbdk in a VM.
FROM debian:squeeze

RUN apt-get update && \
    apt-get install -y make sudo

COPY gbdk /src/gbdk

WORKDIR /src/gbdk

RUN make build-dep

VOLUME /artifacts
RUN make native-build binary
CMD cp *.tar* /artifacts

# Run with:
# sudo docker build -t gbdk-builder .
# sudo docker run --rm=true -i -t -v $PWD/artifacts:/artifacts gbdk-builder

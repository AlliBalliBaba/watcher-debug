FROM golang:1.22-bookworm

ARG EDANT_WATCHER_VERSION=next
WORKDIR /usr/local/src/watcher
RUN curl -L https://github.com/e-dant/watcher/archive/refs/heads/$EDANT_WATCHER_VERSION.tar.gz | tar xz
WORKDIR /usr/local/src/watcher/watcher-$EDANT_WATCHER_VERSION/watcher-c
RUN gcc -o libwatcher.so ./src/watcher-c.cpp -I ./include -I ../include -std=c++17 -O3 -Wall -Wextra -fPIC -shared && \
	cp libwatcher.so /usr/local/lib/libwatcher.so && \
	ldconfig

WORKDIR /go/src/app

COPY . .

RUN gcc watcher-test.c -o watcher-test -lwatcher -lstdc++
ENTRYPOINT ["./watcher-test"]
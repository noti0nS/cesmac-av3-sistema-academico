FROM ubuntu:25.04@sha256:79efa276fdefa2ee3911db29b0608f8c0561c347ec3f4d4139980d43b168d991

WORKDIR /app

COPY . ./

RUN apt-get update && apt-get install -y gcc libc-dev locales && rm -rf /var/lib/apt/lists/* \
    && localedef -i pt_BR -c -f UTF-8 -A /usr/share/locale/locale.alias pt_BR.UTF-8

ENV LANG=pt_BR.utf8

RUN gcc ./main.c -o main.o

ENTRYPOINT [ "./main.o" ]
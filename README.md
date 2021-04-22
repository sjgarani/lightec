# Lightec

## Obter Projetos utilizados

`git submodule update --init --recursive`


## Compile Lightec

`mkdir build`

`cd build/`

`cmake ..`

`make`


## Gerar a Imagem para Raspberry Pi 3

`cd poky`

`source oe-init-build-env`

`bitbake core-image-base`

Param(
    [Parameter(Mandatory=$false)]
    [switch]$build
)

if ($build) {
    docker build -t sistema_academico_app .
}

docker run -it sistema_academico_app
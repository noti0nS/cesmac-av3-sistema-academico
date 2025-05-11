if [[ "$1" == "-build" ]]; then
    echo "Building the Docker image..."
    docker build -t sistema_academico_app .
fi

docker run -it sistema_academico_app

source /repos/user_env.sh

groupmod -g $(stat -c "%g" /var/run/docker.sock) docker

cd /repos/c/cmake/iotsdk_linux/iothub_client/tests/iothubclient_badnetwork_e2e
ctest -j 1


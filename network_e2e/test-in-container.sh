docker run --rm -v /var/run/docker.sock:/var/run/docker.sock -v/repos/:/repos --privileged -it jenkins-image-08 /bin/bash -c /repos/run-test.sh 

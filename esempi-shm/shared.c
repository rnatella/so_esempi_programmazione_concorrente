#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    key_t k = ftok(".", 'a');

    int id_memoria = shmget(k, sizeof(int), IPC_CREAT | 0644);

    if(id_memoria < 0) {
        perror("problema shmget");
        exit(1);
    }


    int * x = shmat(id_memoria, NULL, 0);

    *x = 0;


    pid_t pid = fork();

    if(pid == 0) {

        // qui c'è il figlio

        printf("FIGLIO - Sono il processo figlio (%d)...\n", getpid());

        sleep(3);

        *x = 123;

        printf("FIGLIO - Ho scritto il valore %d\n", *x);

        exit(0);

    }
    else if(pid > 0) {

        // qui c'è il padre

        printf("PADRE - Sono il processo padre (%d)...\n", getpid());

        wait(NULL);

        printf("PADRE - Ho raccolto il valore %d\n", *x);

    }
    else {

        perror("Problema fork");
        exit(1);

    }


    return 0;
}


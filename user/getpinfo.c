#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"

int main(int argc, char *argv[]){
    settickets(29);

    if (argc != 2){
        fprintf(2, "Usage: %s <linhas>\n", argv[0]);
        exit(1);
    }

    const int linhas = atoi(argv[1]);
    if (linhas <= 0) {
        fprintf(2, "Erro: <linhas> deve ser um número positivo\n");
        exit(1);
    }

    int pids[3];

    for (int i = 0; i < 3; i++){
        switch (pids[i] = fork())
        {
        case -1:
            fprintf(2, "Erro ao criar processo filho\n");
            exit(1);
            break;
        case 0:
            settickets(10 + i * 10);
            for (int j = 0; j < 100000000; j++); // Simula carga de trabalho
            exit(0);
            break;
        default:
            break;
        }
    }

    for (int j = 0; j < linhas; j++) {
        fprintf(1, "-------------------------\n");
        struct pstat p;
        int ret = getpinfo(&p);
        if (ret < 0) {
            fprintf(2, "Erro ao chamar getpinfo\n");
            exit(1);
        }
        for (int i = 0; i < NPROC; i++) {
            if (p.inuse[i]) {
                fprintf(1, "pid: %d, tickets: %d, ticks: %d\n", p.pid[i], p.tickets[i], p.ticks[i]);
            }
        }
        sleep(1); // Usar sleep(1) para pausar por 1 segundo
    }

    for (int i = 0; i < 3; i++) {
        wait(0); // Aguarda a conclusão dos processos filhos
    }
    
    exit(0);
}

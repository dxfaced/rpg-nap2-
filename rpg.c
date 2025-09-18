#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TOTAL_PONTOS 40
#define ATRIBUTOS 6

typedef struct {
    char nome[20];
    int sanidade;
    int saude;
    int forca;
    int intelecto;
    int vigor;
    int persuasao;
} Personagem;
 void criarPersonagem(Personagem *p) {
    printf("Digite o nome do personagem: ");
    scanf("%19[^\n]", p->nome);
    while(getchar() != '\n'); // limpar buffer
    int pontos = TOTAL_PONTOS;
    int atribs[6] = {0};
    char *nomesAtribs[6] = {"Sanidade", "Saúde", "Força", "Intelecto", "Vigor", "Persuasão"};
    printf("Distribua %d pontos entre os atributos:\n", TOTAL_PONTOS);
    for(int i = 0; i < 6; i++) {
        int val;
        do {
            printf("%s (pontos restantes %d): ", nomesAtribs[i], pontos);
            scanf("%d", &val);
            while(getchar() != '\n');
            if(val < 0 || val > pontos) {
                printf("Valor inválido. Tente novamente.\n");
            }
        } while(val < 0 || val > pontos);
        atribs[i] = val;
        pontos -= val;
    }
    p->sanidade = atribs[0];
    p->saude = atribs[1];
    p->forca = atribs[2];
    p->intelecto = atribs[3];
    p->vigor = atribs[4];
    p->persuasao = atribs[5];
    printf("\nPersonagem criado com sucesso!\n");
void mostrarAtributos(Personagem p);
}

int rolarD20() {
    return rand() % 20 + 1;
}

void esperar() {
    printf("\nPressione Enter para continuar...");
    while(getchar() != '\n');
}

void mostrarAtributos(Personagem p) {
    printf("\nAtributos do personagem %s:\n", p.nome);
    printf("Sanidade: %d\n", p.sanidade);
    printf("Saúde: %d\n", p.saude);
    printf("Força: %d\n", p.forca);
    printf("Intelecto: %d\n", p.intelecto);
    printf("Vigor: %d\n", p.vigor);
    printf("Persuasão: %d\n", p.persuasao);
}
int main() {
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    Personagem jogador;
    criarPersonagem(&jogador);

    int momento = 1;
    int escolha;
    int dado;
    int final = 0;

    printf("\nBem-vindo ao RPG Chutulo, %s!\n", jogador.nome);
    printf("Você é um investigador experiente, conhecido por sua coragem e intelecto.\n");
    printf("Sua missão é desvendar os mistérios sombrios que assolam a cidade de Arkham.\n");
    printf("Prepare-se para enfrentar horrores indescritíveis e tomar decisões que podem salvar ou condenar sua alma.\n");
    esperar();

    while(momento <= 20 && final == 0) {
        printf("\n--- Momento %d ---\n", momento);

        switch(momento) {
            case 1:
                printf("Você chega à cidade de Arkham ao entardecer. As ruas estão silenciosas e uma névoa espessa cobre tudo.\n");
                printf("1) Investigar a taverna local.\n");
                printf("2) Perguntar aos moradores sobre desaparecimentos.\n");
                printf("3) Explorar a floresta próxima.\n");
                printf("4) Visitar a biblioteca antiga.\n");
                printf("5) Ignorar a cidade e seguir viagem.\n");
                break;
            case 2:
                printf("Você encontra um estranho objeto brilhante no chão.\n");
                printf("1) Pegar o objeto.\n");
                printf("2) Ignorar e continuar.\n");
                printf("3) Mostrar para um morador.\n");
                printf("4) Jogar o objeto no chão.\n");
                printf("5) Guardar para estudar depois.\n");
                break;
            case 3:
                printf("Uma criatura grotesca aparece na floresta.\n");
                printf("1) Atacar com seu bastão.\n");
                printf("2) Fugir para a floresta densa.\n");
                printf("3) Tentar conversar.\n");
                printf("4) Usar um amuleto de proteção.\n");
                printf("5) Se esconder.\n");
                break;
            case 4:
                printf("Você encontra um livro antigo com símbolos estranhos.\n");
                printf("1) Ler o livro.\n");
                printf("2) Queimar o livro.\n");
                printf("3) Guardar o livro.\n");
                printf("4) Mostrar para um especialista.\n");
                printf("5) Ignorar o livro.\n");
                break;
            case 5:
                printf("Sua sanidade está abalada.\n");
                printf("1) Meditar para recuperar.\n");
                printf("2) Beber para esquecer.\n");
                printf("3) Procurar ajuda médica.\n");
                printf("4) Continuar investigando.\n");
                printf("5) Dormir.\n");
                break;
            case 6:
                printf("Você encontra uma passagem secreta.\n");
                printf("1) Entrar na passagem.\n");
                printf("2) Marcar o local e voltar depois.\n");
                printf("3) Ignorar e seguir outro caminho.\n");
                printf("4) Colocar armadilhas.\n");
                printf("5) Gritar para ver se alguém responde.\n");
                break;
            case 7:
                printf("Um morador oferece ajuda suspeita.\n");
                printf("1) Aceitar ajuda.\n");
                printf("2) Recusar educadamente.\n");
                printf("3) Perguntar intenções.\n");
                printf("4) Ignorar e seguir sozinho.\n");
                printf("5) Observar de longe.\n");
                break;
            case 8:
                printf("Você encontra um altar estranho.\n");
                printf("1) Tocar no altar.\n");
                printf("2) Orar para seu deus.\n");
                printf("3) Fotografar o altar.\n");
                printf("4) Ignorar o altar.\n");
                printf("5) Destruir o altar.\n");
                break;
            case 9:
                printf("Você sente uma presença maligna.\n");
                printf("1) Enfrentar a presença.\n");
                printf("2) Fugir.\n");
                printf("3) Usar um talismã.\n");
                printf("4) Gritar por ajuda.\n");
                printf("5) Se esconder.\n");
                break;
            case 10:
                printf("Você encontra um mapa antigo.\n");
                printf("1) Seguir o mapa.\n");
                printf("2) Guardar para depois.\n");
                printf("3) Queimar o mapa.\n");
                printf("4) Mostrar para um aliado.\n");
                printf("5) Ignorar o mapa.\n");
                break;
            case 11:
                printf("Você é atacado por cultistas.\n");
                printf("1) Lutar.\n");
                printf("2) Fugir.\n");
                printf("3) Tentar negociar.\n");
                printf("4) Usar magia.\n");
                printf("5) Se esconder.\n");
                break;
            case 12:
                printf("Você encontra um artefato poderoso.\n");
                printf("1) Usar o artefato.\n");
                printf("2) Guardar com cuidado.\n");
                printf("3) Destruir o artefato.\n");
                printf("4) Vender para um colecionador.\n");
                printf("5) Ignorar o artefato.\n");
                break;
            case 13:
                printf("Sua sanidade está crítica.\n");
                printf("1) Buscar ajuda espiritual.\n");
                printf("2) Tomar remédios.\n");
                printf("3) Continuar investigando.\n");
                printf("4) Descansar.\n");
                printf("5) Desistir da missão.\n");
                break;
            case 14:
                printf("Você encontra um portal estranho.\n");
                printf("1) Entrar no portal.\n");
                printf("2) Estudar o portal.\n");
                printf("3) Fechar o portal.\n");
                printf("4) Ignorar o portal.\n");
                printf("5) Avisar os moradores.\n");
                break;
            case 15:
                printf("Você é capturado por forças desconhecidas.\n");
                printf("1) Tentar escapar.\n");
                printf("2) Negociar.\n");
                printf("3) Esperar uma oportunidade.\n");
                printf("4) Atacar os captores.\n");
                printf("5) Se render.\n");
                break;
            case 16:
                printf("Você encontra um diário com segredos.\n");
                printf("1) Ler o diário.\n");
                printf("2) Queimar o diário.\n");
                printf("3) Guardar o diário.\n");
                printf("4) Mostrar para um aliado.\n");
                printf("5) Ignorar o diário.\n");
                break;
            case 17:
                printf("Você sente que está sendo seguido.\n");
                printf("1) Confrontar quem segue.\n");
                printf("2) Fugir.\n");
                printf("3) Se esconder.\n");
                printf("4) Usar truques para despistar.\n");
                printf("5) Ignorar e continuar.\n");
                break;
            case 18:
                printf("Você encontra um ritual em andamento.\n");
                printf("1) Interromper o ritual.\n");
                printf("2) Observar de longe.\n");
                printf("3) Fugir.\n");
                printf("4) Participar do ritual.\n");
                printf("5) Chamar reforços.\n");
                break;
            case 19:
                printf("Você está perto do objetivo final.\n");
                printf("1) Avançar com cautela.\n");
                printf("2) Atacar de surpresa.\n");
                printf("3) Negociar com o inimigo.\n");
                printf("4) Recuar para planejar.\n");
                printf("5) Usar artefatos coletados.\n");
                break;
            case 20:
                printf("Momento decisivo!\n");
                printf("1) Enfrentar o horror final.\n");
                printf("2) Fugir para salvar a vida.\n");
                printf("3) Usar todo o conhecimento adquirido.\n");
                printf("4) Sacrificar-se para salvar outros.\n");
                printf("5) Tentar selar o mal para sempre.\n");
                break;
            default:
                printf("Momento não implementado.\n");
                break;
        }

        printf("Escolha uma opção (1-5): ");
        scanf("%d", &escolha);
        while(getchar() != '\n');

        if(escolha < 1 || escolha > 5) {
            printf("Escolha inválida! Tente novamente.\n");
            continue;
        }

        dado = rolarD20();
        printf("Você rolou um d20 e tirou: %d\n", dado);

        int sucesso = 0;
        int atributo_relevante = 0;

        // Definir atributo relevante para cada momento e escolha
        switch(momento) {
            case 1:
                if(escolha == 1 || escolha == 2) atributo_relevante = jogador.persuasao;
                else if(escolha == 3) atributo_relevante = jogador.vigor;
                else if(escolha == 4) atributo_relevante = jogador.intelecto;
                else atributo_relevante = jogador.vigor;
                break;
            case 2:
                if(escolha == 1) atributo_relevante = jogador.vigor;
                else if(escolha == 3) atributo_relevante = jogador.persuasao;
                else if(escolha == 5) atributo_relevante = jogador.intelecto;
                else atributo_relevante = jogador.vigor;
                break;
            case 3:
                if(escolha == 1) atributo_relevante = jogador.forca;
                else if(escolha == 2) atributo_relevante = jogador.vigor;
                else if(escolha == 3) atributo_relevante = jogador.persuasao;
                else if(escolha == 4) atributo_relevante = jogador.sanidade;
                else atributo_relevante = jogador.vigor;
                break;
            case 4:
                if(escolha == 1) atributo_relevante = jogador.intelecto;
                else if(escolha == 2) atributo_relevante = jogador.vigor;
                else if(escolha == 4) atributo_relevante = jogador.persuasao;
                else atributo_relevante = jogador.vigor;
                break;
            case 5:
                if(escolha == 1) atributo_relevante = jogador.sanidade;
                else if(escolha == 2) atributo_relevante = jogador.vigor;
                else if(escolha == 3) atributo_relevante = jogador.vigor;
                else if(escolha == 4) atributo_relevante = jogador.intelecto;
                else atributo_relevante = jogador.vigor;
                break;
            // Para os demais momentos, defina atributos relevantes similares
            case 6: atributo_relevante = jogador.intelecto; break;
            case 7: atributo_relevante = jogador.persuasao; break;
            case 8: atributo_relevante = jogador.sanidade; break;
            case 9: atributo_relevante = jogador.sanidade; break;
            case 10: atributo_relevante = jogador.intelecto; break;
            case 11: atributo_relevante = jogador.forca; break;
            case 12: atributo_relevante = jogador.intelecto; break;
            case 13: atributo_relevante = jogador.sanidade; break;
            case 14: atributo_relevante = jogador.intelecto; break;
            case 15: atributo_relevante = jogador.vigor; break;
            case 16: atributo_relevante = jogador.intelecto; break;
            case 17: atributo_relevante = jogador.persuasao; break;
            case 18: atributo_relevante = jogador.forca; break;
            case 19: atributo_relevante = jogador.intelecto; break;
            case 20: atributo_relevante = jogador.intelecto; break;
            default: atributo_relevante = jogador.vigor; break;
        }

        if(dado + atributo_relevante >= 15) sucesso = 1;

        // Narrativas para cada momento e escolha
        switch(momento) {
            case 1:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você faz bons contatos na taverna e obtém informações valiosas.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("Os frequentadores te ignoram e você se sente desconfortável.\n");
                        jogador.sanidade -= 1;
                    }
                } else if(escolha == 2) {
                    if(sucesso) {
                        printf("Moradores contam histórias úteis sobre os desaparecimentos.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("Moradores ficam desconfiados e te expulsam.\n");
                        jogador.sanidade -= 1;
                    }
                } else if(escolha == 3) {
                    if(sucesso) {
                        printf("Você encontra pistas na floresta.\n");
                        jogador.saude += 1;
                    } else {
                        printf("Você erra o salto sobre um precipício e cai, perdendo saúde.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 4) {
                    if(sucesso) {
                        printf("Você descobre informações valiosas na biblioteca.\n");
                        jogador.intelecto += 1;
                    } else {
                        printf("O livro é confuso e te deixa mais perdido.\n");
                        jogador.sanidade -= 1;
                    }
                } else {
                    if(sucesso) {
                        printf("Você segue viagem e evita problemas.\n");
                        jogador.vigor += 1;
                    } else {
                        printf("Ignorar a cidade te faz perder pistas importantes.\n");
                        jogador.intelecto -= 1;
                    }
                }
                break;

            case 2:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("O objeto emite uma energia que te fortalece.\n");
                        jogador.forca += 1;
                    } else {
                        printf("O objeto é amaldiçoado e te causa dano.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 2) {
                    printf("Você ignora o objeto e segue seu caminho.\n");
                } else if(escolha == 3) {
                    if(sucesso) {
                        printf("O morador reconhece o objeto e te ajuda.\n");
                        jogador.persuasao += 1;
                    } else {
                        printf("O morador fica desconfiado e te evita.\n");
                        jogador.sanidade -= 1;
                    }
                } else if(escolha == 4) {
                    printf("Você joga o objeto no chão e ele desaparece misteriosamente.\n");
                } else {
                    printf("Você guarda o objeto para estudar depois.\n");
                }
                break;

                            if(escolha == 1) {
                    if(sucesso) {
                        printf("Você derrota a criatura com seu bastão.\n");
                        jogador.forca += 1;
                    } else {
                        printf("Você erra o golpe e a criatura te fere gravemente.\n");
                        jogador.saude -= 3;
                    }
                } else if(escolha == 2) {
                    if(sucesso) {
                        printf("Você escapa para a floresta em segurança.\n");
                        jogador.vigor += 1;
                    } else {
                        printf("Você é alcançado e ferido.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 3) {
                    if(sucesso) {
                        printf("A criatura se acalma e te deixa passar.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("A criatura não entende e ataca.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 4) {
                    if(sucesso) {
                        printf("O amuleto te protege do ataque.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("O amuleto falha e você é ferido.\n");
                        jogador.saude -= 2;
                    }
                } else { // escolha == 5
                    if(sucesso) {
                        printf("Você se esconde com sucesso.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("Você é descoberto e atacado pela criatura.\n");
                        jogador.saude -= 2;
                    }
                }
                break;
            case 4:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você decifra os símbolos e ganha conhecimento oculto.\n");
                        jogador.intelecto += 1;
                    } else {
                        printf("Os símbolos te confundem e abalam sua sanidade.\n");
                        jogador.sanidade -= 1;
                    }
                } else if(escolha == 2) {
                    printf("Você queima o livro, mas sente que perdeu algo importante.\n");
                    jogador.intelecto -= 1;
                } else if(escolha == 3) {
                    printf("Você guarda o livro para estudar depois.\n");
                } else if(escolha == 4) {
                    if(sucesso) {
                        printf("O especialista ajuda a decifrar o livro, aumentando seu intelecto.\n");
                        jogador.intelecto += 2;
                    } else {
                        printf("O especialista não acredita em você, causando frustração.\n");
                        jogador.sanidade -= 1;
                    }
                } else {
                    printf("Você ignora o livro e segue em frente.\n");
                }
                break;

            case 5:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você medita e recupera parte da sua sanidade.\n");
                        jogador.sanidade += 2;
                    } else {
                        printf("A meditação não ajuda e você continua perturbado.\n");
                        jogador.sanidade -= 1;
                    }
                } else if(escolha == 2) {
                    printf("Você bebe para esquecer, mas isso afeta sua saúde.\n");
                    jogador.saude -= 1;
                } else if(escolha == 3) {
                    if(sucesso) {
                        printf("A ajuda médica melhora sua saúde.\n");
                        jogador.saude += 2;
                    } else {
                        printf("A ajuda médica é insuficiente.\n");
                        jogador.saude -= 1;
                    }
                } else if(escolha == 4) {
                    printf("Você continua investigando, mas sua sanidade piora.\n");
                    jogador.sanidade -= 1;
                } else {
                    printf("Você dorme e recupera um pouco de vigor.\n");
                    jogador.vigor += 1;
                }
                break;

            case 6:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você entra na passagem e encontra um caminho seguro.\n");
                        jogador.intelecto += 1;
                    } else {
                        printf("A passagem é perigosa e você se machuca.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 2) {
                    printf("Você marca o local para voltar depois.\n");
                } else if(escolha == 3) {
                    printf("Ignorar a passagem pode custar pistas importantes.\n");
                    jogador.intelecto -= 1;
                } else if(escolha == 4) {
                    if(sucesso) {
                        printf("Você coloca armadilhas e se sente mais seguro.\n");
                        jogador.vigor += 1;
                    } else {
                        printf("As armadilhas falham e você é surpreendido.\n");
                        jogador.saude -= 1;
                    }
                } else {
                    printf("Gritar não traz resposta, mas alerta inimigos.\n");
                    jogador.sanidade -= 1;
                }
                break;

            case 7:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você aceita a ajuda e ganha um aliado.\n");
                        jogador.persuasao += 1;
                    } else {
                        printf("A ajuda é uma armadilha e você é traído.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 2) {
                    printf("Você recusa educadamente e segue sozinho.\n");
                } else if(escolha == 3) {
                    if(sucesso) {
                        printf("Você descobre as intenções do morador e se prepara.\n");
                        jogador.intelecto += 1;
                    } else {
                        printf("O morador fica irritado e te ameaça.\n");
                        jogador.sanidade -= 1;
                    }
                } else if(escolha == 4) {
                    printf("Ignorar o morador pode ser perigoso.\n");
                    jogador.sanidade -= 1;
                } else {
                    printf("Você observa de longe e evita problemas.\n");
                    jogador.vigor += 1;
                }
                break;

            case 8:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Tocar no altar te concede uma bênção.\n");
                        jogador.sanidade += 2;
                    } else {
                        printf("O altar amaldiçoa você, causando dano.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 2) {
                    printf("Orar te acalma e recupera sanidade.\n");
                    jogador.sanidade += 1;
                } else if(escolha == 3) {
                    printf("Fotografar o altar pode ajudar depois.\n");
                    jogador.intelecto += 1;
                } else if(escolha == 4) {
                    printf("Ignorar o altar mantém você seguro, mas sem ganhos.\n");
                } else {
                    if(sucesso) {
                        printf("Destruir o altar enfraquece o mal na região.\n");
                        jogador.forca += 1;
                    } else {
                        printf("O altar reage e te fere.\n");
                        jogador.saude -= 2;
                    }
                }
                break;

            case 9:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você enfrenta a presença e resiste ao mal.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("A presença te assusta e você perde sanidade.\n");
                        jogador.sanidade -= 2;
                    }
                } else if(escolha == 2) {
                    printf("Fugir te salva, mas você perde uma oportunidade.\n");
                    jogador.vigor -= 1;
                } else if(escolha == 3) {
                    if(sucesso) {
                        printf("O talismã te protege da presença maligna.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("O talismã falha e você é afetado.\n");
                        jogador.sanidade -= 2;
                    }
                } else if(escolha == 4) {
                    printf("Gritar por ajuda não traz ninguém.\n");
                    jogador.sanidade -= 1;
                } else {
                    if(sucesso) {
                        printf("Você se esconde e evita o perigo.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("Você é encontrado e atacado pela presença.\n");
                        jogador.saude -= 2;
                    }
                }
                break;

            case 10:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Seguir o mapa te leva a um local seguro.\n");
                        jogador.intelecto += 1;
                    } else {
                        printf("O mapa é enganoso e você se perde.\n");
                        jogador.saude -= 1;
                    }
                } else if(escolha == 2) {
                    printf("Guardar o mapa pode ser útil depois.\n");
                } else if(escolha == 3) {
                    printf("Queimar o mapa elimina pistas importantes.\n");
                    jogador.intelecto -= 1;
                } else if(escolha == 4) {
                    if(sucesso) {
                        printf("Um aliado ajuda a interpretar o mapa.\n");
                        jogador.persuasao += 1;
                    } else {
                        printf("O aliado não entende o mapa.\n");
                        jogador.sanidade -= 1;
                    }
                } else {
                    printf("Ignorar o mapa pode custar caro.\n");
                    jogador.intelecto -= 1;
                }
                break;

            case 11:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você luta bravamente e derrota os cultistas.\n");
                        jogador.forca += 1;
                    } else {
                        printf("Você é ferido na luta.\n");
                        jogador.saude -= 3;
                    }
                } else if(escolha == 2) {
                    printf("Fugir te salva, mas você perde equipamentos.\n");
                    jogador.vigor -= 1;
                } else if(escolha == 3) {
                    if(sucesso) {
                        printf("Você negocia e evita o combate.\n");
                        jogador.persuasao += 1;
                    } else {
                        printf("A negociação falha e você é atacado.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 4) {
                    if(sucesso) {
                        printf("Você usa magia para afastar os cultistas.\n");
                        jogador.intelecto += 1;
                    } else {
                        printf("A magia falha e você é ferido.\n");
                        jogador.saude -= 2;
                    }
                } else {
                    if(sucesso) {
                        printf("Você se esconde e evita o combate.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("Você é descoberto e atacado.\n");
                        jogador.saude -= 2;
                    }
                }
                break;

            case 12:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("O artefato te concede poderes temporários.\n");
                        jogador.forca += 2;
                    } else {
                        printf("O artefato é instável e te machuca.\n");
                        jogador.saude -= 3;
                    }
                } else if(escolha == 2) {
                    printf("Guardar o artefato pode ser útil.\n");
                } else if(escolha == 3) {
                    printf("Destruir o artefato elimina um perigo.\n");
                    jogador.sanidade += 1;
                } else if(escolha == 4) {
                    printf("Vender o artefato te dá recursos, mas pode atrair inimigos.\n");
                    jogador.persuasao += 1;
                } else {
                    printf("Ignorar o artefato pode ser arriscado.\n");
                    jogador.intelecto -= 1;
                }
                break;

            case 13:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Ajuda espiritual fortalece sua mente.\n");
                        jogador.sanidade += 2;
                    } else {
                        printf("A ajuda não é suficiente.\n");
                        jogador.sanidade -= 1;
                    }
                } else if(escolha == 2) {
                    printf("Remédios aliviam sintomas, mas têm efeitos colaterais.\n");
                    jogador.saude += 1;
                    jogador.vigor -= 1;
                } else if(escolha == 3) {
                    printf("Continuar investigando piora sua sanidade.\n");
                    jogador.sanidade -= 2;
                } else if(escolha == 4) {
                    printf("Descansar ajuda a recuperar saúde e sanidade.\n");
                    jogador.saude += 1;
                    jogador.sanidade += 1;
                } else {
                    printf("Desistir da missão é uma derrota pessoal.\n");
                    final = 2;
                }
                break;

            case 14:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você entra no portal e é transportado para um lugar seguro.\n");
                        jogador.intelecto += 1;
                    } else {
                        printf("O portal te leva a um lugar perigoso.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 2) {
                    printf("Estudar o portal revela segredos importantes.\n");
                    jogador.intelecto += 1;
                } else if(escolha == 3) {
                    if(sucesso) {
                        printf("Você consegue fechar o portal, impedindo o mal.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("Falha ao fechar o portal, o mal se espalha.\n");
                        jogador.sanidade -= 2;
                    }
                } else if(escolha == 4) {
                    printf("Ignorar o portal pode ser perigoso.\n");
                    jogador.sanidade -= 1;
                } else {
                    printf("Avisar os moradores pode trazer ajuda.\n");
                    jogador.persuasao += 1;
                }
                break;

            case 15:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você escapa dos captores com sucesso.\n");
                        jogador.vigor += 1;
                    } else {
                        printf("Você falha na fuga e é ferido.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 2) {
                    printf("Negociar pode ganhar tempo.\n");
                    jogador.persuasao += 1;
                } else if(escolha == 3) {
                    printf("Esperar uma oportunidade pode ser arriscado.\n");
                } else if(escolha == 4) {
                    if(sucesso) {
                        printf("Você ataca os captores e se liberta.\n");
                        jogador.forca += 1;
                    } else {
                        printf("Você é dominado pelos captores.\n");
                        jogador.saude -= 3;
                    }
                } else {
                    printf("Se render pode salvar sua vida, mas a missão falha.\n");
                    final = 2;
                }
                break;

            case 16:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Ler o diário revela segredos cruciais.\n");
                        jogador.intelecto += 2;
                    } else {
                        printf("O diário é perturbador e abala sua sanidade.\n");
                        jogador.sanidade -= 2;
                    }
                } else if(escolha == 2) {
                    printf("Queimar o diário elimina informações importantes.\n");
                    jogador.intelecto -= 1;
                } else if(escolha == 3) {
                    printf("Guardar o diário para estudar depois.\n");
                } else if(escolha == 4) {
                    printf("Mostrar para um aliado pode ajudar.\n");
                    jogador.persuasao += 1;
                } else {
                    printf("Ignorar o diário pode custar caro.\n");
                    jogador.intelecto -= 1;
                }
                break;

            case 17:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você confronta quem te segue e afasta o perigo.\n");
                        jogador.forca += 1;
                    } else {
                        printf("Você é surpreendido e ferido.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 2) {
                    printf("Fugir pode salvar sua vida.\n");
                    jogador.vigor += 1;
                } else if(escolha == 3) {
                    if(sucesso) {
                        printf("Você se esconde com sucesso.\n");
                        jogador.sanidade += 1;
                    } else {
                        printf("Você é descoberto e atacado.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 4) {
                    printf("Usar truques para despistar é inteligente.\n");
                    jogador.intelecto += 1;
                } else {
                    printf("Ignorar o perigo pode ser fatal.\n");
                    jogador.sanidade -= 1;
                }
                break;

            case 18:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você interrompe o ritual e enfraquece o mal.\n");
                        jogador.forca += 1;
                    } else {
                        printf("O ritual é poderoso e você é ferido.\n");
                        jogador.saude -= 3;
                    }
                } else if(escolha == 2) {
                    printf("Observar de longe pode revelar segredos.\n");
                    jogador.intelecto += 1;
                } else if(escolha == 3) {
                    printf("Fugir pode salvar sua vida.\n");
                    jogador.vigor += 1;
                } else if(escolha == 4) {
                    printf("Participar do ritual pode ter consequências.\n");
                    jogador.sanidade -= 2;
                } else {
                    printf("Chamar reforços pode ajudar.\n");
                    jogador.persuasao += 1;
                }
                break;

            case 19:
                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você avança com cautela e evita armadilhas.\n");
                        jogador.intelecto += 1;
                    } else {
                        printf("Você cai em uma armadilha e se machuca.\n");
                        jogador.saude -= 2;
                    }
                } else if(escolha == 2) {
                    if(sucesso) {
                        printf("Ataque surpresa é eficaz.\n");
                        jogador.forca += 1;
                    } else {
                        printf("O inimigo estava preparado e você é ferido.\n");
                        jogador.saude -= 3;
                    }
                } else if(escolha == 3) {
                    printf("Negociar pode evitar combate.\n");
                    jogador.persuasao += 1;
                } else if(escolha == 4) {
                    printf("Recuar para planejar pode ser sábio.\n");
                    jogador.intelecto += 1;
                } else {
                    printf("Usar artefatos pode virar o jogo.\n");
                    jogador.intelecto += 1;
                }
                break;

            case 20:
                                if(escolha == 1) {
                    if(sucesso) {
                        printf("Você enfrenta o horror final com coragem e consegue derrotá-lo!\n");
                        final = 1; // final bom
                    } else {
                        printf("Você falha no confronto e é consumido pelo horror.\n");
                        jogador.saude = 0;
                        final = 2; // final ruim
                    }
                } else if(escolha == 2) {
                    printf("Você decide fugir para salvar sua vida, abandonando a missão.\n");
                    final = 3; // final neutro
                } else if(escolha == 3) {
                    if(sucesso) {
                        printf("Usando todo seu conhecimento, você sela o mal para sempre.\n");
                        final = 1;
                    } else {
                        printf("Seu conhecimento não é suficiente e o mal prevalece.\n");
                        final = 2;
                    }
                } else if(escolha == 4) {
                    printf("Você se sacrifica para salvar outros, um ato heroico.\n");
                    final = 1;
                } else {
                    if(sucesso) {
                        printf("Você consegue selar o mal para sempre, trazendo paz.\n");
                        final = 1;
                    } else {
                        printf("Sua tentativa falha e o mal retorna com força.\n");
                        final = 2;
                    }
                }
                break;

            default:
                printf("Momento não implementado.\n");
                break;
        }

        // Ajustar limites dos atributos
        if(jogador.sanidade < 0) jogador.sanidade = 0;
        if(jogador.sanidade > 10) jogador.sanidade = 10;
        if(jogador.saude < 0) jogador.saude = 0;
        if(jogador.saude > 10) jogador.saude = 10;

        // Verificar condições de fim de jogo
        if(jogador.saude == 0) {
            printf("\nVocê morreu devido aos ferimentos.\n");
            final = 2;
        } else if(jogador.sanidade == 0) {
            printf("\nVocê perdeu toda a sanidade e enlouqueceu.\n");
            final = 2;
        }

        mostrarAtributos(jogador);

        if(final != 0) break;

        momento++;
        esperar();
    }

    // Exibir resultado final
    printf("\nFim do jogo!\n");
    if(final == 1) {
        printf("Parabéns, %s! Você completou sua missão com sucesso.\n", jogador.nome);
    } else if(final == 2) {
        printf("Infelizmente, %s, você falhou em sua missão.\n", jogador.nome);
    } else if(final == 3) {
        printf("Você sobreviveu, %s, mas a missão não foi concluída.\n", jogador.nome);
    } else {
        printf("O jogo terminou sem um final definido.\n");
    }

    return 0;
    }
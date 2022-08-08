/*
 Guia01 - v1.0. - 08 / 08 / 2022
 Author: Iago Adrien De Paula Simões
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o KarelAtividades ./KarelAtividades.cpp
 No Windows: g++ -o KarelAtividades.exe KarelAtividades.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./KarelAtividades
 No Windows: KarelAtividades
*/
//---------------------------------------------------------------------------------------------
// -[Bibliotecas]
#include <iostream>
#include <string>
#include "karel.hpp"

using namespace std;

//---------------------------------------------------------------------------------------------

// -[Classe para definir o robo]
class MyRobot : public Robot
{
public:
    //------------------------------------------------------------------------
    // -{Virar o robo para a direita}
    void turnRight()
    {
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            turnLeft();
            turnLeft();
            turnLeft();
        } // end if
    }     // end turnRight ( )
    //------------------------------------------------------------------------
    // -[Mover]
    void moveN(int steps) // Repetição de movimento (Recursividade)
    {
        // testar se a quantidade de passos e' maior que zero
        if (steps > 0)
        {
            // dar um passo
            move();
            // tentar fazer de novo, com menos um passo dessa vez
            moveN(steps - 1);
        } // end if
    }     // end moveN( )
    //------------------------------------------------------------------------
    // -[Pegar Beeper]
    void getBeeper()
    {
        // conferir se há beeper no local
        if (nextToABeeper())
        {
            // tentar pegar o Beeper se tiver
            pickBeeper();
        } // end if
    }
    //------------------------------------------------------------------------
    // -[Colocar todos os Beeper da mochila no local]
    void getAllBeeper(int n) // numeros de beepers na mochila
    {
        if (n > 0)
        {
            getBeeper();         // coloca um beepers
            getAllBeeper(n - 1); // tira um valor do beeper colocado e repita a função
        }
    } // metedo usado [recursividade]
    //------------------------------------------------------------------------
    // -[Colocar Beeper]
    void dropBeeper()
    {
        // Conferir se há Beepers na mochila
        if (beepersInBag())
        {
            // tentar colocar se tiver no local em que o Robo está
            putBeeper();
        } // end if
    }
    //------------------------------------------------------------------------
    // -[Colocar todos os Beeper da mochila no local]
    void dropAllBeeper(int n) // numeros de beepers na mochila
    {
        if (n > 0)
        {
            putBeeper();          // coloca um beepers
            dropAllBeeper(n - 1); // tira um valor do beeper colocado e repita a função
        }
    } // metedo usado [recursividade]
    //------------------------------------------------------------------------
    //-[Colocar Beeper "se tiver"]
    void ifHavedropBeeper()
    {
        // testar se carrega marcador antes ...
        if (nbeepers() > 0)
        {
            // ... de tentar descarrega-lo
            putBeeper();
        } // end if
    }
    // Caso nao tenha nenhum beeper na bag, esse if é ignorado e o comando putBeeper() não é executado
    //------------------------------------------------------------------------

    // -[controle do Robo - Guia0111]

    void doTask0111()
    {

        // Primeiro Drop de beeper (3,3)
        moveN(2);
        turnLeft();
        moveN(2);
        dropBeeper();
        // Segundo Drop de beeper (3,6)
        moveN(3);
        dropBeeper();
        // Ultimo Drop de beeper (6,6)
        turnRight();
        moveN(3);
        dropBeeper();
        // Voltar ate o ponto de origem (1,1)
        turnRight();
        moveN(5);
        turnRight();
        moveN(5);
        turnLeft();
        turnLeft();
        // desligar Robo
        turnOff();
    }
    //------------------------------------------------------------------------

    // -[controle do Robo - Guia0112]

    void doTask0112()
    {

        // Primeiro get de beeper (3,3)
        moveN(2);
        turnLeft();
        moveN(2);
        getBeeper();
        // Segundo get de beeper (3,6)
        moveN(3);
        getBeeper();
        // Ultimo get de beeper (6,6)
        turnRight();
        moveN(3);
        getBeeper();
        // Voltar ate o ponto de origem (1,1)
        turnRight();
        moveN(5);
        turnRight();
        moveN(5);
        turnLeft();
        turnLeft();
        // desligar Robo
        turnOff();
    }
    //------------------------------------------------------------------------

    // -[controle do Robo - Guia0113]
    int i{0};
    void move_put(int n)
    {
        if (n > 0)
        {
            dropBeeper();
            moveN(1);
            move_put(n - 1);
            i = i + 1;
        }
        if (i == 3)
        {
            moveN(2);
        }
    }

    void doTask0113()
    {

        // Primeiro get de beeper (3,3)
        moveN(2);
        turnLeft();
        moveN(2);
        getBeeper();
        // Segundo get de beeper (3,6)
        moveN(3);
        getBeeper();
        // Ultimo get de beeper (6,6)
        turnRight();
        moveN(3);
        getBeeper();
        // Voltar ate o ponto de origem (1,1)
        turnRight();
        moveN(5);
        turnRight();
        move_put(3);
        turnLeft();
        turnLeft();
        // desligar Robo
        turnOff();
    }
    //------------------------------------------------------------------------

    // -[controle do Robo - Guia0114]

    int pick04{5};

    void move_pick04(int n)
    {
        if (n > 0)
        {
            moveN(pick04);
            pick04 = pick04 - 1;
            turnLeft();
            moveN(3);
            getBeeper();
            turnLeft();
            turnLeft();
            move();
            turnRight();
            moveN(pick04);
            pick04 = pick04 - 1;
            turnRight();
            moveN(pick04);
            getBeeper();
            move_pick04(n - 1);
        }
    }

    void doTask0114()
    {

        // Pegar os beepers das coordenadas [6,3] e [2,6]
        move_pick04(1);
        // pegar o ultimo beepers
        move();
        turnRight();
        moveN(3);
        getBeeper();
        // entrar dentro a caixa
        move();
        turnRight();
        move();
        turnRight();
        moveN(2);
        turnLeft();
        moveN(2);
        // colocar todos os beepers no chao
        dropAllBeeper(3);
        // sair do local dos beepers
        turnLeft();
        turnLeft();
        moveN(2);
        turnRight();
        moveN(2);
        // Voltar ate o ponto de origem (1,1)
        turnRight();
        moveN(5);
        turnRight();
        move_put(3);
        turnLeft();
        turnLeft();

        // desligar Robo
        turnOff();
    }
    //------------------------------------------------------------------------
    // -[controle do Robo - Guia0115]

    int pick05{3};

    void move_pick05(int n)
    {
        if (n > 0)
        {
            turnLeft();
            moveN(3);
            getAllBeeper(pick05);
            moveN(3);
            turnLeft();
            move();
            getAllBeeper(2);
        }
    }

    void doTask0115()
    {

        moveN(5);
        // Pegar os beepers de valor 3 e 2
        move_pick05(1);
        // pegar o ultimo beeper
        moveN(3);
        turnLeft();
        move();
        getBeeper();
        // ir para a casa 6,6
        turnLeft();
        turnLeft();
        move();
        turnRight();
        moveN(4);
        turnRight();
        // entrar dentro a caixa
        move();
        turnRight();
        moveN(2);
        turnLeft();
        moveN(2);
        // colocar todos os beepers no chao
        dropAllBeeper(6);
        // sair do local dos beepers
        turnLeft();
        turnLeft();
        moveN(2);
        turnRight();
        moveN(2);
        // Voltar ate o ponto de origem (1,1)
        turnRight();
        moveN(5);
        turnRight();
        move_put(3);
        turnLeft();
        turnLeft();

        // desligar Robo
        turnOff();
    }
    //------------------------------------------------------------------------

}; // end class MyRobot

//---------------------------------------------------------------------------------------------

// -[Objetvos]

/**
    - o robô partir da posição inicial (coluna=1, linha=1), voltado para leste,
    com três marcadores ("beepers");
    - o robô deverá colocar um marcador nas posições indicadas:
    (3,3), (3,6) e (6,6), nessa ordem;
    - retornar à posição inicial,
    voltar-se para o leste. e
    desligar-se
**/
//---------------------------------------------------------------------------------------------
// -[Decorando e defindo objetivos]
//--------------------------------------------------------
// -[Criar o mundo para o Karel]
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
//--------------------------------------------------------
// -[Decoração do mundo - Guia0111]
void decorateWorld0111(const char *fileName)
{

    //~{Definir paredes}

    //~{Colocar marcadores}
    /**
     O próprio deixará os marcadores nas seguintes posições
     (3,3) (3,6) (6,6)
    */

    //~[Salvar o mundo criado]
    world->save(fileName);

} // decorateWorld0111 ()

void Guia0111()
{

    // -{Criando o ambiente}
    world->create(""); // criar mundo
    decorateWorld0111("Guia0111.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();              // limpar configurações
    world->read("Guia0111.txt"); // Ler configuração para definir o mundo
    world->show();               // Mostrar o mundo lido do arquivo Guia0111.txt
    set_Speed(3);                // Definir velocidade de movimento do robo (3 - padrão)

    // -{Criando o robo}
    MyRobot *robot = new MyRobot(); // criando um novo robo
    //            (x, y, direção, marcadores, Karel )
    robot->create(1, 1, EAST, 3, "Karel"); // Definindo o spawn do robo e seu marcadores

    // -{Move o Robo e seguir com os objetivos}
    robot->doTask0111();

    // Encerrar o cenario
    world->close();

    // Encerrar atividade
    cout << "aperte ENTER para encerrar" << endl;
    getchar();
    // Limpar o cmd/cenario
    system("cls");
}
//--------------------------------------------------------
// -[Decorando o mundo - Guia0112]
void decorateWorld0112(const char *fileName)
{

    //~{Definir paredes}

    //~{Colocar marcadores}
    world->set(3, 3, BEEPER);
    world->set(3, 6, BEEPER);
    world->set(6, 6, BEEPER);

    //~[Salvar o mundo criado]
    world->save(fileName);

} // decorateWorld0112 ()

void Guia0112()
{

    // -{Criando o ambiente}
    world->create(""); // criar mundo
    decorateWorld0112("Guia0112.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();              // limpar configurações
    world->read("Guia0112.txt"); // Ler configuração para definir o mundo
    world->show();               // Mostrar o mundo lido do arquivo Guia0111.txt
    set_Speed(3);                // Definir velocidade de movimento do robo (3 - padrão)

    // -{Criando o robo}
    MyRobot *robot = new MyRobot(); // criando um novo robo
    //            (x, y, direção, marcadores, Karel )
    robot->create(1, 1, EAST, 0, "Karel"); // Definindo o spawn do robo e seu marcadores

    // -{Move o Robo e seguir com os objetivos}
    robot->doTask0112();

    // Encerrar o cenario
    world->close();

    // Encerrar atividade
    cout << "aperte ENTER para encerrar" << endl;
    getchar();
    // Limpar o cmd/cenario
    system("cls");
}

//--------------------------------------------------------
// -[Decorando o mundo - Guia0113]
void decorateWorld0113(const char *fileName)
{

    //~{Definir paredes}

    //~{Colocar marcadores}
    world->set(3, 3, BEEPER);
    world->set(3, 6, BEEPER);
    world->set(6, 6, BEEPER);

    //~[Salvar o mundo criado]
    world->save(fileName);

} // decorateWorld0113 ()

void Guia0113()
{

    // -{Criando o ambiente}
    world->create(""); // criar mundo
    decorateWorld0113("Guia0113.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();              // limpar configurações
    world->read("Guia0113.txt"); // Ler configuração para definir o mundo
    world->show();               // Mostrar o mundo lido do arquivo Guia0111.txt
    set_Speed(3);                // Definir velocidade de movimento do robo (3 - padrão)

    // -{Criando o robo}
    MyRobot *robot = new MyRobot(); // criando um novo robo
    //            (x, y, direção, marcadores, Karel )
    robot->create(1, 1, EAST, 0, "Karel"); // Definindo o spawn do robo e seu marcadores

    // -{Move o Robo e seguir com os objetivos}
    robot->doTask0113();

    // Encerrar o cenario
    world->close();

    // Encerrar atividade
    cout << "aperte ENTER para encerrar" << endl;
    getchar();
    // Limpar o cmd/cenario
    system("cls");
}

//--------------------------------------------------------
// -[Decorando o mundo - Guia0114]
void decorateWorld0114(const char *fileName)
{

    //~{Definir paredes}
    world->set(3, 6, HWALL);
    world->set(4, 6, HWALL);
    world->set(5, 6, HWALL);

    world->set(3, 3, HWALL);
    world->set(4, 3, HWALL);
    world->set(5, 3, HWALL);

    world->set(2, 4, VWALL);
    world->set(2, 5, VWALL);
    world->set(2, 6, VWALL);

    world->set(5, 4, VWALL);
    world->set(5, 5, VWALL);

    //~{Colocar marcadores}
    world->set(2, 6, BEEPER);
    world->set(5, 7, BEEPER);
    world->set(6, 4, BEEPER);

    //~[Salvar o mundo criado]
    world->save(fileName);

} // decorateWorld0114 ()

void Guia0114()
{

    // -{Criando o ambiente}
    world->create(""); // criar mundo
    decorateWorld0114("Guia0114.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();              // limpar configurações
    world->read("Guia0114.txt"); // Ler configuração para definir o mundo
    world->show();               // Mostrar o mundo lido do arquivo Guia0111.txt
    set_Speed(3);                // Definir velocidade de movimento do robo (3 - padrão)

    // -{Criando o robo}
    MyRobot *robot = new MyRobot(); // criando um novo robo
    //            (x, y, direção, marcadores, Karel )
    robot->create(1, 1, EAST, 0, "Karel"); // Definindo o spawn do robo e seu marcadores

    // -{Move o Robo e seguir com os objetivos}
    robot->doTask0114();

    // Encerrar o cenario
    world->close();

    // Encerrar atividade
    cout << "aperte ENTER para encerrar" << endl;
    getchar();
    // Limpar o cmd/cenario
    system("cls");
}

//--------------------------------------------------------
// -[Decorando o mundo - Guia0115]
void decorateWorld0115(const char *fileName)
{

    //~{Definir paredes}
    world->set(3, 6, HWALL);
    world->set(4, 6, HWALL);
    world->set(5, 6, HWALL);

    world->set(3, 3, HWALL);
    world->set(4, 3, HWALL);
    world->set(5, 3, HWALL);

    world->set(2, 4, VWALL);
    world->set(2, 5, VWALL);
    world->set(2, 6, VWALL);

    world->set(5, 4, VWALL);
    world->set(5, 5, VWALL);

    //~{Colocar marcadores}
    world->set(2, 6, BEEPER);

    world->set(5, 7, BEEPER);
    world->set(5, 7, BEEPER);

    world->set(6, 4, BEEPER);
    world->set(6, 4, BEEPER);
    world->set(6, 4, BEEPER);

    //~[Salvar o mundo criado]
    world->save(fileName);

} // decorateWorld0115 ()

void Guia0115()
{

    // -{Criando o ambiente}
    world->create(""); // criar mundo
    decorateWorld0115("Guia0115.txt");
    world->show();

    // preparar o ambiente para uso
    world->reset();              // limpar configurações
    world->read("Guia0115.txt"); // Ler configuração para definir o mundo
    world->show();               // Mostrar o mundo lido do arquivo Guia0111.txt
    set_Speed(2);                // Definir velocidade de movimento do robo (3 - padrão)

    // -{Criando o robo}
    MyRobot *robot = new MyRobot(); // criando um novo robo
    //            (x, y, direção, marcadores, Karel )
    robot->create(1, 1, EAST, 0, "Karel"); // Definindo o spawn do robo e seu marcadores

    // -{Move o Robo e seguir com os objetivos}
    robot->doTask0115();

    // Encerrar o cenario
    world->close();

    // Encerrar atividade
    cout << "aperte ENTER para encerrar" << endl;
    getchar();
    // Limpar o cmd/cenario
    system("cls");
}

//--------------------------------------------------------
//---------------------------------------------------------------------------------------------
// -[Cadeia onde será executado as funções das atividades pedidas]
int main(void)
{
    system("cls");
    // dados
    int opcao{0};

    // repetir ate desejar parar
    do
    {
        // indentificar
        cout << "----------------------------------" << endl;
        cout << "Guia01 - Karel - 08/08/2022" << endl;
        cout << "Matricula: 770493" << endl;
        cout << "Nome: Iago Adrien De Paula Simoes" << endl;

        // mostrar opções
        cout << "----------------------------------" << endl;
        cout << "[0] Encerrar programa" << endl;
        cout << "[1] Atividade 01" << endl;
        cout << "[2] Atividade 02" << endl;
        cout << "[3] Atividade 03" << endl;
        cout << "[4] Atividade 04" << endl;
        cout << "[5] Atividade 05" << endl;
        cout << "----------------------------------" << endl;

        // Ler opção
        cout << "Qual opcao?" << endl;
        cin >> opcao;

        // Ir a opção desejada
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            Guia0111();
            break;
        case 2:
            Guia0112();
            break;
        case 3:
            Guia0113();
            break;
        case 4:
            Guia0114();
            break;
        case 5:
            Guia0115();
            break;

        default:
            cout << "ERRO: Opcao invalida." << endl;
            break;
        } // fim escolher

    } while (opcao != 0);

} // end main()
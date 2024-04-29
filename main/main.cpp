#include <iostream>
#include <conio.h>

using namespace std;

/**
* DEFINI플O DAS ESTRUTURAS
*/

struct Cidade
{
    long codigo;
    string nome;
    char uf[2];
};

struct EspecialidadeMedica
{
    long codigo;
    string descricao;
};

struct CID
{
    long codigo;
    string descricao;
};

struct Medico
{
    long codigo;
    string nome;
    EspecialidadeMedica especialidadesMedicas[22]; //Tamanho de 22 porque existem 22 especialidades.
    string endereco;
    string telefone;
    Cidade cidade;
};

struct Paciente
{
    string cpf;
    string nome;
    string endereco;
    Cidade cidade;
};

struct Medicamento
{
    long codigo;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unidade;
};

struct DateTime
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};

struct Consulta
{
    Paciente paciente;
    Medico medico;
    DateTime dataHora;
    CID cid;
    Medicamento Medicamentos[10];
    int qtde_medicamento[10];
};

/**
* FIM DAS STRUCT
*/


/**
* DEFINI플O DAS FUN합ES EX1
*/

void inserirCidade(struct Cidade cidades[], int maximo, int &constCidade)
{

    int i, codigo = 1;
    if(constCidade < 0) i = constCidade+1;
    else i = constCidade;
    for(;i < maximo && codigo > 0;)
    {
        system("cls");
        cout << "Informe o codigo da Cidade: (Insira 0 para fechar)\n";
        cin >> codigo;
        if(codigo > 0) {
            cidades[i].codigo = codigo;
            cout << "Informe o nome da Cidade: ";
            cin.ignore();
            getline( cin, cidades[i].nome );
            cout << "Informe o UF da Cidade: ";
            cin >> cidades[i].uf;
            i++;
        }
        system("cls");
    }
    constCidade = i;
}

void exibirCidades(struct Cidade cidades[], int constCidade)
{
    if(constCidade > 0) {
        cout << "\t\tCIDADE\t\n";
        cout << "Codigo\t|\tNome\t|\tUF\n";
        for(int i = 0; i < constCidade; i++)
        {
            cout << cidades[i].codigo << "\t|\t" << cidades[i].nome << "\t|\t" << cidades[i].uf << endl;
        }
    } else cout << "Lista vazia";
    getch();

}

void inserirEspecialidades(struct EspecialidadeMedica especialidades[], int maximo, int &constEspecialidade)
{

    int i, codigo = 1;
    if(constEspecialidade < 0) i = constEspecialidade+1;
    else i = constEspecialidade;
    for(;i < maximo && codigo > 0;)
    {
        system("cls");
        cout << "Informe o codigo da Especialidade: (Insira 0 para fechar)\n";
        cin >> codigo;
        if(codigo > 0) {
            especialidades[i].codigo = codigo;
            cout << "Informe a descricao da Especialidade: ";
            cin.ignore();
            getline( cin, especialidades[i].descricao );
            i++;
        }
        system("cls");
    }
    constEspecialidade = i;

}

void exibirEspecialidades(struct EspecialidadeMedica especialidades[], int constEspecialidade)
{
    if(constEspecialidade > 0) {
        cout << "\tESPECIALIDADE\t\n";
        cout << "Codigo\t|\tDesc\n";
        for(int i = 0; i < constEspecialidade; i++)
        {
            cout << especialidades[i].codigo << "\t|\t" << especialidades[i].descricao << endl;
        }
    } else cout << "Lista vazia";
    getch();

}

void inserirCID(struct CID cids[], const int maximo, int &constCID)
{

    int i, codigo = 1;
    if(constCID < 0) i = constCID+1;
    else i = constCID;
    for(;i < maximo && codigo > 0;)
    {
        system("cls");
        cout << "Informe o codigo da CID: (Insira 0 para fechar)\n";
        cin >> codigo;
        if(codigo > 0) {
            cids[i].codigo = codigo;
            cout << "Informe a descricao da CID: ";
            cin.ignore();
            getline( cin, cids[i].descricao );
            i++;
        }
        system("cls");
    }
    constCID = i;

}

void exibirCID(struct CID cids[], int constCID)
{

    if(constCID > 0) {
        cout << "\tCID\t\n";
        cout << "Codigo\t|\tDesc\n";
        for(int i = 0; i < constCID; i++)
        {
            cout << cids[i].codigo << "\t|\t" << cids[i].descricao << endl;
        }
    } else cout << "Lista vazia";
    getch();

}

void inserirMedicamentos(struct Medicamento medicamentos[], const int maximo, int &constMedicamento)
{

    int i, codigo = 1;
    if(constMedicamento < 0) i = constMedicamento+1;
    else i = constMedicamento;
    for(;i < maximo && codigo > 0;)
    {
        system("cls");
        cout << "Informe o codigo da Medicamento: (Insira 0 para fechar)\n";
        cin >> codigo;
        if(codigo > 0) {
            medicamentos[i].codigo = codigo;
            cout << "Informe a descricao do Medicamento: ";
            cin.ignore();
            getline( cin, medicamentos[i].descricao );
            cout << "Informe a qtde no estoque: ";
            cin >> medicamentos[i].quant_estoque;
            cout << "Informe o minimo no estoque: ";
            cin >> medicamentos[i].estoque_minimo;
            cout << "Informe o maximo no estoque: ";
            cin >> medicamentos[i].estoque_maximo;
            cout << "Informe o preco da unidade: ";
            cin >> medicamentos[i].preco_unidade;
            i++;
        }
        system("cls");
    }
    constMedicamento = i;

}

void exibirMedicamentos(struct Medicamento medicamentos[], int constMedicamento)
{

    if(constMedicamento > 0) {
        cout << "\t\t\t\tMedicamento\t\n";
        cout << "Codigo\t|\tDesc\t|\tQtde\t|\tMin\t|\tMax\t|\tPreco\n";
        for(int i = 0; i < constMedicamento; i++)
        {
            cout << medicamentos[i].codigo << "\t|\t" << medicamentos[i].descricao
            << "\t|\t" << medicamentos[i].quant_estoque
            << "\t|\t" << medicamentos[i].estoque_minimo
            << "\t|\t" << medicamentos[i].estoque_maximo
            << "\t|\t" << medicamentos[i].preco_unidade << endl;
        }
    } else cout << "Lista vazia";
    getch();

}

/**
* FIM DAS FUNCOES EX1
*/

/**
* DEFINI플O DAS FUN합ES EX2
*/



/**
* FIM DAS FUNCOES EX2
*/

int main()
{
    //DECLARANDO VARIAVEIS
    const int maximo = 30, maximoEspecialidade = 22;
    struct Cidade cidades[maximo];
    struct EspecialidadeMedica especialidades[maximoEspecialidade];
    struct CID cids[maximo];
    struct Medicamento medicamentos[maximo];
    int constCidade = -1, constEspecialidade = -1, constCID = -1, constMedicamento = -1;

    //DECLARANDO AS FUN합ES]
    int i, j;
    do
    {
        cout << "Informe se deseja inserir ou exibir dados: \n(1 para Inserir, 2 para Exibir, 0 para fechar)\n";
        cin >> i;
        system("cls");
        if(i == 1) {
            cout << "Informe qual deseja inserir: \n(1 para Cidade, 2 para Especialidades, 3 para CID e 4 para Medicamentos)\n";
            cin >> j;
            system("cls");
            if(j == 1) {
                inserirCidade(cidades, maximo, constCidade);
            } else if(j == 2) {
                inserirEspecialidades(especialidades, maximoEspecialidade, constEspecialidade);
            } else if(j == 3) {
                inserirCID(cids,maximo,constCID);
            } else if(j == 4) {
                inserirMedicamentos(medicamentos, maximo, constMedicamento);
            } else {
                cout << "Codigo informado nao existe!";
                getch();
            }
        } else if(i == 2) {
            cout << "Informe qual deseja exibir: \n(1 para Cidade, 2 para Especialidades, 3 para CID e 4 para Medicamentos)\n";
            cin >> j;
            system("cls");
            if(j == 1) {
                exibirCidades(cidades, constCidade);
            } else if(j == 2) {
                exibirEspecialidades(especialidades, constEspecialidade);
            } else if(j == 3) {
                exibirCID(cids,constCID);
            } else if(j == 4) {
                exibirMedicamentos(medicamentos, constMedicamento);
            } else {
                cout << "Codigo informado nao existe!";
                getch();
            }
        } else if(i > 0) {
            cout << "Codigo informado nao existe!";
            getch();
        }
        system("cls");
    } while(i != 0);
}

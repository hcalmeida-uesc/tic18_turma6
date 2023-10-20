#include <iostream>
#include <vector>

using namespace std;

class Paciente{
    string cpf;
    string dtNascimento; //ideal tipo Data ou struct tm
    public:
        string nome;

        Paciente(string _nome,string _cpf,string _dtNascimento){
            this->nome = _nome;
            this->setCpf(_cpf);
            this->setDtNascimento(_dtNascimento);
        }

        string getCpf(){
            return this->cpf;
        }

        void setCpf(string _cpf){
            /* validar quantidade de caracteres 11 ou 14
            */
           this->cpf = _cpf;
        }

        string getDtNascimento(){
            return this->dtNascimento;
        }

        void setDtNascimento(string _dtNascimento){
            /* validar quantidade de caracteres e formato
            */
           this->dtNascimento = _dtNascimento;
        } 
};

// funcao para localizar cpf em um vector<Paciente*>
int localizaCpf(vector<Paciente*> pacientes, string cpf){
    int i=0;
    for(auto el : pacientes){
        if(el->getCpf() == cpf){
            return i;
        }
        i++;
    }

    return -1;
}

int main(){

    int opcao;
    vector<Paciente*> listaPacientes;

    do{
        cout << "Informe a opção (0-5): " << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir (por CPF)" << endl;
        cout << "3. Alterar (por CPF)" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar (por CPF)" << endl;
        cout << "0. Sair" << endl;
        cin >> opcao;

        string auxNome, auxCpf, auxDtNasc;
        if(opcao==1){
            cout << "Informe o nome: ";
            getline(cin >> ws, auxNome);

            cout << "Informe o CPF: ";
            getline(cin >> ws, auxCpf);

            cout << "Informe a Data de Nascimento: ";
            getline(cin >> ws, auxDtNasc);

            Paciente *paciente = new Paciente(auxNome, auxCpf, auxDtNasc);

            //TODO: procurar em listaPacientes pelo cpf do novo paciente

            listaPacientes.push_back(paciente);
        }
        else if(opcao==2){
            cout << "Informe o CPF do paciente que deseja excluir: ";
            getline(cin >> ws, auxCpf);

            /*
                buscar pelo paciente em listaPacientes
            */
        }
        else if(opcao==3){
            cout << "Informe o CPF do paciente que deseja alterar: ";
            getline(cin >> ws, auxCpf);

            /*
                buscar pelo paciente em listaPacientes
                em seguida pedir os dados que deseja alterar
            */
        }else if(opcao==4){
            for(auto el : listaPacientes){
                cout << el->nome << endl;
                cout << el->getCpf() << endl;
                cout << el->getDtNascimento() << endl;
                cout << endl;
            }
        }else if(opcao==5){
            cout << "Informe o CPF do paciente que deseja alterar: ";
            getline(cin >> ws, auxCpf); 

            int posicao = localizaCpf(listaPacientes,auxCpf);

            if(posicao < 0)
                cout << "Paciente não encontrado" << endl;
            else{
                cout << listaPacientes.at(posicao)->nome << endl;
            }
        }else if(opcao==0){
            // sair desse menu
        } else{
            cout << "Opção inválida" << endl;
        }
    }while(opcao != 0);

    
    return 0;
}
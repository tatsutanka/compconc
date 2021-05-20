/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:11/05/2021*/


import java.lang.Math; // biblioteca responsavel por numeros aleatorios

// Estrutura compartilhada entre as Threads
class Estrutura{
    // intendificador do sensor
    //indentifcador de leitura = quantos leitores ja acessaram 
    // a variavel 

    public Estrutura(){

    }
}

//monitor que implementa a logica do padrao leitor/escritor
class LE{

    private int leit, escr;

    public LE(){
        this.leit = 0;// leitores lendo (0 ou mais)
        this.escr = 0;//escritor escrevendo (0 ou 1)
    }

    public synchronized void EntLeitor(int id) {
        try {
            while (this.escr > 0) {
                wait(); //bloqueia pela condicao logica
            }
            this.leit++; 
        } catch (InterruptedException e)         
    }

    public synchronized void SaiLeitor(int id ) {
        this.leit--;
        if(this.leit == 0){
            this.notify(); // libera escritor caso exista escritor bloqueado
        }
        
    }
    public synchronized void EntEscritor(int id) {
        try {
                while (this.leit > 0 || this.escr > 0) {
                    wait(); 
                }
                this.escr++;
             } catch (InterruptedException e) {
    }
    public synchronized void SaiEscitor(int id) {
       this.escr--; // registra a saida do escritor
       notifyAll(); //libera leitores e escritores ( caso existam bloqueados)
    }
}



//Aplicacao de exemplo--------------------------------------------------------
//Leitor = atuador 
// o atuador deve 
class Leitor extends Thread{
    int id;
    Estrutura e;//Estrutura compartilhada entre as Threads
    LE monitor;//objeto monitor para coordenacao da execucao 
    
    public Leitor(int id, LE m,Estrutura e) {
        this.e = e;
        this.id = id; 
        this.monitor = m;
    }

    public void run() {
       try {
            for(;;){
                this.monitor.EntLeitor();
                Thread.sleep(2000);
                // caso as ultimas 5 leituras derem acima de 
                // 35 graus emitir luz vermelho
                //
                // caso as ultimas 15 leituras derem acima de 
                // 35 graus emitir luz amarelo
                // 
                // 5 leitores indentifcados derem maio que 35
                // alerta amarelo
                //
                // caso nao de em nada o atuador vai dar um 
                // sinal de normal 
                this.monitor.SaiLeitor();
            }
        } catch (InterruptedException e) {return;}
    }

}
//--------------------------------------------------------
//Escritor = sensor
//Os sensores deverao medir a temperatura em intervalos
//de aproximadamente 1 segundo  o valor medio simulado etre 
//[25 ... 40] 
class Escritor extends Thread{
    int id;
    private simulado = 0;
    Estrutura e; //Estrutura compartilhada entre as Threads
    LE monitor;//objeto monitor para coordenacao da execucao 

    public Escritor(int id, LE m,Estrutura e) {
        this.e = e;
        this.id = id; 
        this.monitor = m;
    }

    public void run() {
       try {
            for(;;){
                this.monitor.EntEscritor();
                Thread.sleep(1000);
                simulado = ((int) (Math.random() * (40 - 25))) + 10);
                // sempre que o valor simulado for maior que 
                // 30 o valor vai ser escrito na variavel 
                // compartilhada com o valor do indentificador 
                // do sendsor e o indentificador de leitura 
                this.monitor.SaiEscitor();
            }
        } catch (InterruptedException e) {return;} 
    }
}

//--------------------------------------------------------
//classe principal 
class Trab2 {
    static final int L = 4; // numero de Threads Leitoras
    static final int E = 3; // numeor de Threads Escritoras

    public static void main(String[] args) {
        int i;
        Estrutura e = new Estrutura();
        LE monitor = new LE();
        Leitor[] l = new Leitor[L];
        Escritor e = new Escritor[E];
        
        
        if(args.length < 2){
         
        }
        // transformar String em numero 
        // L e E serao especificados na linha de comando 
        
        //inicia as Threads
        for(i=0; i<L; i++) {
           l[i] = new Leitor();
           l[i].start(); 
        }
        for(i=0; i<E; i++) {
           e[i] = new Escritor();
           e[i].start(); 
        }

        // Espera o terminao das Threads quado o programa é 
        // chamdo para o termino 

    }

}

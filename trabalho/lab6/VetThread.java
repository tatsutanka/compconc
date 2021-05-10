/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:20/04/2021*/

//estrutura compartilhada entre as Threads
class Estrutura{
    //recurso compartilhado
    private int vetor[];
    private int size;

    //incremento da posicao i em 1
    public void inc(int i) {
       this.vetor[i]++; 
    }

    public  int getSize() {
        return this.size;
    }

    public void getVetor(){
        for (int v : vetor) {
            System.out.print(v + " ");
        }
        System.out.println();
    }

    public Estrutura(int n){
        this.vetor = new int[n];
        this.size = n;
        for (int i = 0; i < n; i++) {
            this.vetor[i] = 1;
        }
        System.out.println("Tamanho Vetor:" + n);
    }
}


class T extends Thread{
    // numero de Threads
    private int nThreads;
    //identificador da Thread
    private int id;
    //Objeto compartilhado entre as Threads
    Estrutura t;

    public T(int n, int tid,Estrutura t) {
        this.id = tid;
        this.t = t;
        this.nThreads = n;
    }

    public void run() {
        System.out.println("Thread " + this.id + " iniciou!");
        for (int i = this.id; i < this.t.getSize(); i+=this.nThreads) {
            this.t.inc(i);
        }
        System.out.println("Thread " + this.id + " terminou!");
    }
}

//--classe do metodo main
class VetThread {
   static final int N = 10;

   public static void main (String[] args) {
      //--reserva espaço para um vetor de threads
      Thread[] threads = new Thread[N];

      // criar instancia do ojbeto compartilhado
      Estrutura t = new Estrutura(2*N);

      //--PASSO 2 cria as Threads da aplicaçao
      for (int i=0; i<threads.length; i++) {
         threads[i] = new T(N,i, t);
      }

      //--PASSO 3: iniciar a thread
      for (int i=0; i<threads.length; i++) {
         threads[i].start();
      }

      //--PASSO 4: esperar pelo termino das threads
      for (int i=0; i<threads.length; i++) {
            try { threads[i].join(); } 
            catch (InterruptedException e) { return; }
      }
        
      t.getVetor();
      System.out.println("Terminou"); 
   }
}


#include <stdio.h>
#include <unistd.h>

int main (){
  int ptc[2], ctp[2], READ, WRITE;
  READ = 0;
  WRITE = 1;
  pipe(ptc);
  pipe(ctp);
  //parent
  if(fork()){
    int number = 11;
    close(ptc[READ]);
    close(ctp[WRITE]);
    
    write(ptc[WRITE], &number, sizeof(number));
    printf("[parent] sending: %d\n", number );

    read(ctp[READ], &number, sizeof(number));
    printf("[parent] received: %d\n", number);
  }
  //child
  else{
    int numb;
    close(ptc[WRITE]);
    close(ctp[READ]);

    read(ptc[READ], &numb, sizeof(numb));
    printf("[child] does math on: %d\n", numb );

    numb = numb * (numb + 1);
    write(ctp[WRITE], &numb, sizeof(numb));
  }
  return 0;
}


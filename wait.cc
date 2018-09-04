//file:wait.cc
//version:0.0.0.1

#include <iostream>
#include <thread>


using namespace std;
using namespace std::chrono;



float star(float previous,int current,int max){
int const DISPLAY_STEPS=80;


if(current==0){
  cout << "[" << flush;
  for(int i=0;i<DISPLAY_STEPS;i++){
  cout << "-" << flush;
  }
  cout << "]" << endl << flush;
  cout << "[" << flush;
  return 0;
}


float steps=(float) max/(float)DISPLAY_STEPS;
float change=(float)current-(float)previous;
int step_count=change /steps;


if(step_count<1){
  return previous;
}


for(int i=0;i<step_count;i++){
  cout << "*" << flush;
}
 previous+=(float) step_count * steps;


  if(current==max){
    cout << "]"  << endl << flush;
  }
 return previous;
}





void wait(int seconds){
  time_point<system_clock> start=system_clock::now();
  time_point<system_clock>  current=system_clock::now();
  chrono::seconds sec=chrono::duration_cast<chrono::seconds>(current - start);

  float last=0;
  star(0,0,seconds);
  while(sec.count() < seconds){
     this_thread::sleep_for(1s);
     current=chrono::system_clock::now();
     sec=chrono::duration_cast<chrono::seconds>(current - start);
     //cout << sec.count() << endl;
    last=star(last,sec.count(),seconds);
  }


}


int main(int argc,char* argv[]){

  wait(3 *  60);
  return 0;
}

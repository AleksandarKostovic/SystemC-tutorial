////////////////////////////////////////////////
// This module is not syntesizable!           //
// Because the cout is not syntesizable.      // 
// This is used for simulation purposes only. //
////////////////////////////////////////////////


#include <systemc.h>

SC_MODULE (hello) {  // module named hello
  SC_CTOR (hello) {  //constructor phase, which is empty in this case
  }

  void say_hello() {
    std::cout << "Hello World!" << std::endl;
  }
};

int sc_main(int argc, char* argv[]) {
  hello h("hello");
  h.say_hello();
  return 0;
}

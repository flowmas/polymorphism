
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fruit {
 public:
  virtual ~Fruit() = default;
  virtual int eat() = 0;
  int energy{0};
};


class Apple : public Fruit {
 public:
  Apple() { energy = 10; }
  int eat() override {
    cout << "Ate apple" << endl;
    return energy;
  }
};

class Banana : public Fruit {
 public:
  Banana() { energy = 20; }
  int eat() override {
    cout << "Ate banana" << endl;
    return energy;
  }
};

class FruitFactory {
 public:
  static Fruit *create(const string& name) {
    if (name == "apple")
      return new Apple();
    if (name == "banana")
      return new Banana();
    return nullptr;
  }

};

void FruitTest() {
  vector<Fruit *> eaten;
  string name;
  int totalEnergy{0};
  cout << "Give name: ";
  while (cin >> name && name.empty()) {
    Fruit *f = FruitFactory::create(name);
    if (f) {
      totalEnergy += f->eat();
    }
    cout << "Give name: ";
  }
  cout << "Total Energy: " << totalEnergy << endl;
  for (const auto& f: eaten)
    delete f;
}

int main() {
  FruitTest();
  return 0;
}

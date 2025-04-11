#ifndef PALLET_H
#define PALLET_H

class Pallet{
    public:
        Pallet(int id, double weight, double value);
        ~Pallet();
        int getId();
        double getWeight();
        double getValue();
    private:
        int id;
        double weight;
        double value;
};

Pallet::Pallet(int id, double weight, double value) : id(id), weight(weight), value(value) {}

Pallet::~Pallet() {}

int Pallet::getId(){
    return id;
}

double Pallet::getWeight(){
  return weight;
}

double Pallet::getValue(){
  return value;
}

#endif //PALLET_H

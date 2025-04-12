#ifndef PALLET_H
#define PALLET_H

class Pallet{
    public:
        Pallet(int id, double weight, double value);
        ~Pallet();
        int getId() const;
        double getWeight() const;
        double getValue() const;
    private:
        int id;
        double weight;
        double value;
        double ratio;
};

#endif //PALLET_H

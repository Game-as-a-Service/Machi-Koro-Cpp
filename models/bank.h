#ifndef MODELS_BANK_H
#define MODELS_BANK_H

class Bank {
public:
    Bank() = default;

    Bank(int coin);

    ~Bank() = default;

    void payCoin(int coin) { coin_ -= coin; }

    void gainCoin(int coin) { coin_ += coin; }

    int totalCoin() const { return coin_; }

private:
    int coin_ = 282;
};

#endif  // MODELS_BANK_H
#include "models/dice_base.h"

#include <gmock/gmock.h>

class MockDice : public DiceBase {
public:
    MOCK_METHOD(int, generatePoint, (), (const override));
};
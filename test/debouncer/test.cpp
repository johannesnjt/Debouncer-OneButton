#include <Arduino.h>
#include <unity.h>
#include "BSP.h"
#include "Debouncer.h"

void Debouncer_update();
uint8_t Debouncer_get_button_state(uint8_t);

void test_debouncer_loop()
{
    /*
    Debouncer_init();
    Debouncer_update();
    state = Debouncer_get_button_state(33);
    uint8_t = state;
    bsp_set_fake_value(33);
    debouncer_update;
    state = debouncer_get_state(33);
    debouncer_update; */

    uint8_t current_state;

    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debounce(0));
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debounce(0));
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debounce(0));
    TEST_ASSERT_EQUAL_UINT8(DEBOUNCER_HIGH, debounce(0));
}

void setUp()
{
}

void tearDown() {}

#ifdef TEST_ON_PC
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_debouncer_loop);

    return UNITY_END();
}

#endif
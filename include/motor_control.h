#ifndef SIMPLE_PWM_MOTOR_CONTROL_H
#define SIMPLE_PWM_MOTOR_CONTROL_H

#include "pico/stdlib.h"
#include <cmath>
#include <cstdio>
#include "hardware/pwm.h"

// Define PWM resolution
#define TOP 1000
#define SYSTEM_CLOCK 125000000  // 125 MHz
#define PWM_FREQUENCY 19500  // 20 kHz

class DCMotor {
public:
    DCMotor(uint enA_pin, uint enB_pin, uint pwm_pin, float min_duty, float max_duty);

    void set_pwm_frequency(float frequency);
    void write_int16(int16_t pwm);
    void write(float duty_cycle);

    float get_rpm() const { return _rpm; }
    float get_speed() const { return _speed; }
    void set_rpm(float rpm) { _rpm = rpm; }
    void set_speed(float speed) { _speed = speed; }

private:
    uint _enA_pin;
    uint _enB_pin;
    uint _pwm_pin;
    uint _slice_num;
    uint _channel;

    float _rpm;
    float _speed;

    float _min_duty;
    float _max_duty;

};

#endif //SIMPLE_PWM_MOTOR_CONTROL_H

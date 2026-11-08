# ASW_EVSE — EV Charging Station Controller

## Hardware
- **MCU:** STM32L431CB (64KB flash — smallest in the family)
- **CAN Node:** 6 (NODEID_EVSE)
- **HWID:** 0x106
- **Device string:** "UHA-EVSE 1.0"

## Role
Controls the AC EV charging station (Type 2 / SAE J1772). Manages the control pilot protocol, charging current negotiation, relay switching, session energy tracking, and user interface.

---

## Key Modules

| Module | Role |
|--------|------|
| EVSE | SAE J1772 state machine + control pilot voltage monitoring |
| ST7066U | 16×2 character LCD driver (4-bit parallel) |
| ELM | Pulse-count energy meter for session tracking |
| ADC | Control pilot voltage measurement (12-bit) |
| di | 3-button input debouncing (ENTER, UP, DOWN) |
| UI | Status LEDs (Life, Error, Status) |

---

## SAE J1772 State Machine

| State | CP Voltage | Meaning |
|-------|-----------|---------|
| evsNoCarDetected | > 10V | No vehicle |
| evsCarFull | 8–10V | Vehicle connected, not accepting charge |
| evsCharging | 2–8V | Active charging session |
| evsNoFreePower | — | System disallows charging |
| evsDisabled | — | User-disabled |
| evsError | < 2V | Protocol/hardware fault |

**CP signal:** 1kHz PWM, duty cycle encodes max current (IEC 62196: 10–90% duty = 6–51A in 0.6A steps).

---

## Charging Current Control
- **Range:** 6A minimum — 16A maximum (EVSE_MAX_CURRENT)
- **User adjustment:** UP/DOWN buttons ±1A per press
- **AC relay:** Gates three-phase power on/off at state transition → evsCharging

---

## User Interface
**3 buttons:** ENTER (toggle enable/disable), UP (increase current limit), DOWN (decrease)

**16×2 LCD** shows:
- Line 1: Status — "No Vehicle", "Charging: XXXxW", "Vehicle charged", "No free power", "Disabled by user", "EVSE ERROR!"
- Line 2: Current limit, power, session energy

**Status LEDs:** Life (heartbeat), Error (fault), Status (charging active)

---

## Energy Meter
- Single pulse-count meter (ELM_EVSE) on EL1_Pin via GPIO interrupt
- Tracks per-session energy (reset at session start)
- VAR_CONS_EVSE_WH — published to CAN

---

## Published VARS
| VAR | Content |
|-----|---------|
| VAR_CONS_EVSE_WH | Session energy consumed (Wh) |
| VAR_POW_EVSE_W | Instantaneous charging power (W) |

---

## Read from CAN
- Charging enable/disable commands from energy management (ELECON_D via LEMON load control)
- RTC sync

---

## Notes
- Smallest MCU in the project (64KB flash) — keep code lean
- SAE J1772 compliance is safety-critical — CP voltage thresholds must not be relaxed
- Watchdog: 3-second timeout

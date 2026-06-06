# vesak_lantern_arduino
For a vesak lantern design build by team of us and my part was building the light system and I used arduino with 8 relay module to create a cuztomizable pattern for the lantern.
+----------------------------------------+
        |            Arduino Uno / Nano          |
        |                                        |
        |   D2   D3   D4   D5   D6   D7   D8   D9  |
        +---|----|----|----|----|----|----|----|-+
            |    |    |    |    |    |    |    |  
            |    |    |    |    |    |    |    |  (Control Lines)
            v    v    v    v    v    v    v    v  
        +----------------------------------------+
        | IN1  IN2  IN3  IN4  IN5  IN6  IN7  IN8 |
        |                                        |
        |         8-Channel Relay Module         |
        |           (Active-Low Logic)           |
        |                                        |
        | GND =============================== GND|---> To Controller GND
        | VCC =============================== 5V |---> To Controller 5V
        +----------------------------------------+

        Component Name,Arduino Digital Pin,Relay Channel,Description
upGreen,D2,CH1,Top Array — Green Channel
upRed,D3,CH2,Top Array — Red Channel
upBlue,D4,CH3,Top Array — Blue Channel
downGreen,D5,CH4,Bottom Array — Green Channel
downRed,D6,CH5,Bottom Array — Red Channel
downBlue,D7,CH6,Bottom Array — Blue Channel
upWhite,D8,CH7,Top Array — High-Power White
downWhite,D9,CH8,Bottom Array — High-Power White


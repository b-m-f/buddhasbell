# Steps to implement

1. Motion detected -> Motor an zum hochziehen und turn off motion detection
2. 30 sekunden warten nach motor oben -> motor start reverse
3. (Mensch sind drin) -> 30 sekunden warten
4. start pure data audio installation
.
.
.
9. Motor an hoch 
10. 30 sekunden warten
11. Motor reverse und zu, motion detection wieder aktiviert




# Notes
## Sicherheitsmechanismus um aus zu steigen (Schnuar oder Knopf)
1. Motor an hoch 
2. 30 sekunden warten
3. Motor reverse und zu, motion detection wieder aktiviert


# simulation
- sensor triggered motor
- delay 30
- motor geht runter
- delay 10
- pd startet -> pd schickt zurueck zum arduino
- motor geht hoch
- delay 20s
- motor geht runter
- sensor wieder aktiv + LED an, dass ready


# zusammenfassung des codes in klartext

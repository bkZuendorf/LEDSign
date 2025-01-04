# Entwurf der Leuchtreklame
Im ersten Schritt muss ein Entwurf der Leuchreklamen erfolgen. Das kann „per Hand“ gezeichnet, mit CAD gezeichnet oder gar durch Programmierung simuliert werden.
Dabei sollten folgende Aspekte  berücksichtigt werden:
    1. Einfache Logos verwenden, die mit max. 100 LEDs einen guten Eindruck vermitteln können
    2. Maße der verfügbaren 3mm Hartfaserplatten berücksichtigen 
(24 x 24 cm oder 18 x 30 cm)
    3. LED Größe von ca. 5mm berücksichtigen
    4. Mindestabstand von 5mm zwischen den LEDs einhalten
    5. Überlegen wie max. 8 Leuchtgruppen sinnvoll gebildet werden können
Beispielsweise kann mit der Programmierumgebung „Processing“ eine Simulation entworfen werden:
 

Anordnung der LEDa anhand eines Bildes


Test/Simulation der Leuchgruppen


Erstellung einer Bohrschablone

Der Quellcode für das Programm liegt vor und kann für das eigene Logo angepasst werden.
2 Umsetzung der Reklame
Mit Hilfe der aus dem Entwurf hervorgegangenen Bohrschablone können nun die Löcher in die Hartfaserplatte gebohrt werden.
Es stehen unterschiedliche LEDs zum Betrieb an 5 V zur Verfügung. Teilweise ist eine Reihenschaltung von 2 LEDs mit einem Vorwiderstand möglich.
Sämtliche +-Potenziale werden miteineinander verbunden, die GND-Potenziale werden in max. 8 verschiedenen Gruppen verlötet.


In der Vergangenheit wurden untenstehende Werte genutzt. Es ist sinnvoll, das Leuchtverhalten mit jeder neuen LED Charge im Vorfeld zu prüfen.
Nr
Farbe
Einzelschaltung
2-fach Reihenschaltung
1
Rot
220 Ω
56 Ω
2
Gelb
220 Ω
56 Ω
3
Weiß
1,2 kΩ
Nicht möglich
4
Blau
1,2 kΩ
Nicht möglich
5
Orange
330 Ω
100 Ω
6
Grün
100 Ω
15 Ω

Zur Ansteuerung der Leuchtreklamen können folgende Platinen gelötet werden.
Dabei werden wahlweise die Mikrocontroller-Boards „Arduino Nano“ oder „Wemos D1 Mini“ verwendet.
Der Quellcode für das Programm liegt vor und kann nach eigenen Wünschen angepasst werden.
3 Rahmen
Für die Gestaltung eines Rahmens müssen zu den 4 gedruckten Rahmenecken Latten (19 x 5mm) gesägt werde :
    • 4 Stück a 22,4cm
    • 4 Stück a 24 cm










4 Arduino Nano LDR Variante



Vorderansicht
Rückansicht (der LDR kann je nach Wunsch auf der Vorder- oder Rückseite verlötet werden)

Die empfohlene Lötreihenfolge ist:
    1. LEDs (Polarität beachten! Anode auf Seite des Widerstandsnetzwerks!)
       
    2. IC, Taster, Widerstände, Widerstandsnetzwerk, LDR
    3. Buchsen, Stiftleisten
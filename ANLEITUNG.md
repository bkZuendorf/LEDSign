# 1 Entwurf der Leuchtreklame
<table>
<tr>
    <td><img src="https://github.com/user-attachments/assets/d23f5ae3-cc62-4f4b-82be-2bed176e1a19" height="300"/></td>
    <td><img src="https://github.com/user-attachments/assets/f5f01227-0a57-4d28-81e3-48456d1de248" height="300"/></td>
    <td><img src="https://github.com/user-attachments/assets/32ceee8c-6525-4c8e-ae65-d7121a615efe" height="300"/></td>
</tr>    
</table>
In diesem Projekt soll eine Leuchtreklame mit klassischen 5mm-LEDs erstellt werden. Dies kann wahlweise durch Bohren einer Hartfaserplatte oder durch Drucken eines Gehäuses geschehen.

Im ersten Schritt muss ein Entwurf der Leuchtreklamen erfolgen. Dieser Entwurf kann „per Hand“ oder CAD gezeichnet oder durch Programmierung (z.B. mit Processing) simuliert werden.
Dabei sollten folgende Aspekte berücksichtigt werden:
    1. Einfache Logos/Darstellungen wählen, die mit max. 100 LEDs einen guten Eindruck vermitteln können
    2. Maße der verfügbaren 3mm Hartfaserplatten berücksichtigen (24 x 24 cm oder 18 x 30 cm)
    3. LED Größe von ca. 5mm berücksichtigen
    4. Mindestabstand von 5mm zwischen den LEDs einhalten
    5. Sinnvolle Ausnutzung der max. 8 Leuchtgruppen 
    
Beispielsweise kann mit der Programmierumgebung „Processing“ eine Simulation entworfen werden:
<table>
<tr><td><img src="https://github.com/user-attachments/assets/db959853-fbfb-4723-81a1-62edb5ac81aa" /></td><td><img src="https://github.com/user-attachments/assets/ee04879f-d8d3-4a20-afde-4201cc26e4f0"  /></td>
<td><img src="https://github.com/user-attachments/assets/9b8fbb7f-10c1-4b6a-81b2-2f3dc8793025" /></td>
</tr>
<tr><td>Anordnung der LEDs anhand eines Bildes</td><td>Test/Simulation der Leuchtgruppen</td><td>Erstellung einer Bohrschablone</td></tr>    
</table>

Der Quellcode für das Programm liegt vor und kann für das eigene Logo angepasst werden.

# 2 Herstellung der Reklame
Mit Hilfe der aus dem Entwurf hervorgegangenen Bohrschablone können nun die Löcher in die Hartfaserplatte gebohrt werden.
Es stehen unterschiedliche LEDs zum Betrieb an 5 V zur Verfügung. Teilweise ist eine Reihenschaltung von 2 LEDs mit einem Vorwiderstand möglich.
Sämtliche +-Potenziale werden miteineinander verbunden, die GND-Potenziale werden in max. 8 verschiedenen Gruppen verlötet.
![image](https://github.com/user-attachments/assets/73ebc791-8ab1-41f6-a8fe-c7b91f7c4080)

In der Vergangenheit wurden untenstehende Werte genutzt. Es ist sinnvoll, das Leuchtverhalten mit jeder neuen LED-Charge im Vorfeld zu prüfen.
|Nr|Farbe|Einzelschaltung|2-fach Reihenschaltung|
|---|---|---|---|
|1|Rot|220 Ω|56 Ω|
|2|Gelb|220 Ω|56 Ω|
|3|Weiß|1,2 kΩ|Nicht möglich|
|4|Blau|1,2 kΩ|Nicht möglich|
|5|Orange|330 Ω|100 Ω|
|6|Grün|100 Ω|15 Ω|

Zur Ansteuerung der Leuchtreklamen können folgende Platinen gelötet werden.
Dabei werden wahlweise die Mikrocontroller-Boards „Arduino Nano“ oder „Wemos D1 Mini“ verwendet.
Der Quellcode für das Programm liegt vor und kann nach eigenen Wünschen angepasst werden.

# 3 Rahmen
Für die Gestaltung eines Rahmens müssen zu den 4 gedruckten Rahmenecken Latten (19 x 5mm) gesägt werde :
    • 4 Stück a 22,4cm
    • 4 Stück a 24 cm
![image](https://github.com/user-attachments/assets/b96f4767-9304-4545-b5fe-5cdf66de3208)

# 4 Arduino Nano LDR Variante
<table>
<tr>
    <td><img src="https://github.com/user-attachments/assets/d78d9f28-5d2f-430b-843f-1b405d2fc462" /></td><td><img src="https://github.com/user-attachments/assets/17263233-2057-4c5b-bb2e-ca663359db72"  /></td>
</tr>
<tr><td>Vorderansicht</td><td>Rückansicht (der LDR kann je nach Wunsch auf der Vorder- oder Rückseite verlötet werden)</td></tr>    
</table>


Die empfohlene Lötreihenfolge ist:
1. LEDs (Polarität beachten! Anode auf Seite des Widerstandsnetzwerks!)       
2. IC, Taster, Widerstände, Widerstandsnetzwerk, LDR
3. Buchsen, Stiftleisten

![image](https://github.com/user-attachments/assets/f5638a70-708c-4374-9cda-70cb43ea2728)

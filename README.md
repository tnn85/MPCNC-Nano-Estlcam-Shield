
# MPCNC-Nano-Estlcam-Shield
English: A CNC shield for the MPCNC in conjunction with Estlcam  
Deutsch: Ein CNC Shield für die MPCNC in Verbindung mit Estlcam

# Konzept:  
Eine CNC Steuerung für die MPCNC und Estlcam, die Einsteigern eine kostengünstige, auf die CNC-Maschine (MPCNC) und Software (Estlcam) zugeschnittene Steuerung als Lösung anbietet.  Die Steuerung erlaubt mehr Funktionen als vergleichbare Steuerungen (z. B. das GRBL 0.8 "CNC Shield V3"), auf die Schrittmotortreibermodule (A4988, DRV8825, etc) gesteckt werden können und stellt zusätzlich eine Erweiterungsmöglichkeit für genauere, leistungsähigere Schrittmotortreiber bereit.

# Name:

 ***"MPCNC Nano Estlcam Shield"***  
 * __"MPCNC"__: Richtet sich vorrangig an Einsteiger in Thema CNC, die mit der MPCNC  anfangen wollen und somit direkt die Kompatibiliät erkennen  
 * __"Nano"__: Auf Arduino Nano basierend  
 * __"Estlcam"__: Ist für die Verwendung mit Estlcam als Steuerungs- und CAM-Software zugeschnitten  
 * __"Shield"__: Soll ausdrücken, dass es, wie bei der Terminologie von Arduino üblich, als Zusatzmodul/"Piggyback" zum Arduino fungieren soll.
 
# Technische Anforderungen:

* Unterstützt Estlcam Version 11
* Zweilagige Platine
* Nur THT-Bauteile (kein SMD-Löten erforderlich)
* Schraubklemmen oder Stiftleisten fürr Anschluss externer Komponenten
* Betrieb mit 12 - 36V -> Spannungsregler 5V + 12V erforderlich
* Verpolungsschutz der Versorgung 
* Steckplätze für Pololu Schrittmotortreibermodule DRV8825 + A4988 bzw. Trinamic SilentStepStick TMC2100 
* Serienschaltung von X- und Y-Achsen über Jumper
* Anschlussmöglichkeit für Bluetoothmodul (Übertragung von Estlcam über virtuelle serielle Schnittstelle) -> Rücksprache mit Christian Knüll von Estlcam erforderlich.
* Lüfteranschluss 12V (keine Regelung über Temperatur, Spannungsregler 12V erforderlich ) 
* Individuelle Erkennung der linken+rechten Endstopps (2x X-Achse, 2x Y-Achse, 1x Z-Achse) über 5/8 Eingängen möglich
* 2 Ausgänge für Relais, SSR, (Open Collector)
* 8 galvanisch getrennte Eingänge
* Spindel ON/OFF (galvanisch getrennt) +  Drehzahl (PWM / 0-5V / 0-10V) Ausgänge
* 2 analoge Eingänge Drehzahl + Vorschubanpassung
* Testpunkte für Fehlersuche

# Optionale Anforderungen:

* Signalisierrung der Eingänge über LED
* Drehzahlsteuerung von Spindeln/Fräsmotoren ohne FU
* Temperaturabhängige Lüfterreglung über PWM
* Absaugautomatik mit Nachlaufverzögerung 
* Auto Square
* Sicherung für Treiber



# Ordnerstruktur:

* KiCad-Projektdatei
* Schematic(Ordner für Schaltplan)
* PCB Layout (Ordner für Platinenlayout)
* Firmware (Ordner für Firmware für Mikrocontroller, falls Mikrocontroller enthalten)
* Enclosure (Ordner für Gehäuse-CAD-Dateien, STL-Dateien, Stecker)
* Docs (Ordner für Anleitung, Verkabelungsbeispiele, Technisches Datenblatt, etc)
* Parts (Ordner für Datenblätter, Bill of Materials, Lieferanten, etc)
* Readme 
* License




# Lizenz:
* Creative Commons CC-BY-SA-NC 4.0 License

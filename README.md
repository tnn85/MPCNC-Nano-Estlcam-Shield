
# MPCNC-Nano-Estlcam-Shield
English: A CNC shield for the MPCNC in conjunction with Estlcam  
Deutsch: Ein CNC Shield für die MPCNC in Verbindung mit Estlcam

# Konzept:  
Das MPCNC Nano Esltcam Shield stellt eine CNC Steuerungssplatine für die MPCNC bereit, die Einsteigern eine kostengünstige, auf die CNC-Maschine (MPCNC) und Software (Estlcam) zugeschnittene Steuerung als Schnittstellenlösung zwischen Maschine und Estlcam anbietet.  Die Steuerung bietet mehr Funktionalität als vergleichbare Steuerungen (z. B. das bekannte GRBL 0.8 "CNC Shield V3"), auf die Schrittmotortreibermodule (A4988, DRV8825, etc) gesteckt werden können und stellt zusätzlich eine Erweiterungsmöglichkeit für genauere, leistungsähigere Schrittmotortreiber bereit.

# Name:

 ***"MPCNC Nano Estlcam Shield"***  
 * __"MPCNC"__: Richtet sich vorrangig (aber nicht nur) an Einsteiger in Thema CNC, die mit der MPCNC  anfangen wollen und somit direkt die Kompatibiliät erkennen  
 * __"Nano"__: Auf Arduino Nano basierend  
 * __"Estlcam"__: Ist für die Verwendung mit Estlcam als Steuerungs- und CAM-Software zugeschnitten  
 * __"Shield"__: Soll ausdrücken, dass es, wie bei der Terminologie von Arduino üblich, als Zusatzmodul/"Piggyback" zum Arduino fungieren soll.
 
# Technische Anforderungen:

* Unterstützt Estlcam Version 11 (GRBL oder andere Firmware kann nach entsprechender Konfiguration auch mit der Platine verwendet werden)
* Arduino Nano Support (Original oder Klon)
* Zweilagige Platine
* Nur THT-Bauteile (kein SMD-Löten erforderlich)
* Schraubklemmen oder Stiftleisten für Anschluss externer Komponenten
* Betrieb mit 12-36V
* Konfiguration über Jumper
* Verpolungsschutz Versorgungsanschluss 
* Steckplätze für Pololu Schrittmotortreibermodule DRV8825 + A4988. TMC21x0 sollte auch funktionieren, wurde noch nicht getestet. 
* Mikrostepping über Jumper für Aufstecktreiber einstellbar
* Serienschaltung von zwei Schrittmotoren für X- und Y-Achsen. Einzelner Motor über Jumper auch im Einzelbetrieb möglich.
* Anschlussmöglichkeit von externen Treibern für alle 3 Achsen (DIR, STEP/PUL, GND). Es können auch Servomotoren damit angesteuert werden.
* Lüfteranschluss 12V 
* 7(8) galvanisch getrennte Eingänge (für Eingang 6 muss die Diode auf dem Arduino entfernt werden)
* Ausreichend Eingänge für Endstops/Programmsteuerung/Werkzeuglängensensor/Tastplatte. Eingänge beliebig konfigurierbar.
* 2 Ausgänge für Relais/SSR/etc mit 5V/12V/Open Collector. Ausgänge können über Estlcam angesteuert werden.
* Signalisierrung der Eingänge/Ausgänge über LEDs möglich (für Ausgänge schon vorhanden, bei Eingängen in Reihe schaltbar) 
* Spindel ON/OFF (galvanisch getrennt) +  Drehzahl (PWM / 0-5V / 0-10V) Ausgänge
* 2 analoge Eingänge Drehzahl + Vorschubanpassung
* optional erweiterbar durch ATTiny µC (greift Drehzahlsignal ab) 
* Testpunkte für Fehlersuche

# Optionale Anforderungen:

* Erweiterung um Handradsteuerung (vorraussichtlich nicht möglich, da von Estlcam-seitig unterbunden)
* Drehzahlsteuerung von Spindeln/Fräsmotoren ohne FU über µC ATTiny
* Temperaturabhängige Lüfterreglung über PWM mit Temperaturalarm
* Absaugautomatik mit Nachlaufverzögerung 
* Auto Square
* Sicherung für Treiber
* Unterstützung für Trinamic SilentStepStick TMC2100/2130/2208/5160 (Konfiguration über Tristate-Jumper, Seriell, SPI) 
* Anschlussmöglichkeit für Bluetoothmodul (Übertragung von Estlcam über virtuelle serielle Schnittstelle)

# Ordnerstruktur:

* KiCad-Projektdatei
* Schematic (*.sch)
* PCB Layout (*.kicad_pcb)
* Netzliste (*.net)
* Firmware (Ordner für Firmware für Mikrocontroller)
* Enclosure (Ordner für Gehäuse-CAD-Dateien, STL-Dateien, Stecker)
* Docs (Ordner für Anleitung, Berechnungen, Verkabelungsbeispiele, Technisches Datenblatt, etc)
* Parts (Ordner für Datenblätter, Bill of Materials, Lieferanten, etc)
* Libraries (Ordner für projektspezifische Bauteilsymbole und Footprints)
* Readme 
* License




# Lizenz:
* Creative Commons CC-BY-SA-NC 4.0 License

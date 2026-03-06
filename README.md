# RC-Flugzeugbau
RC-Flugzeugbauprozess, Programmierung, Konstruktion.
Über das Projekt

Schon seit meiner Kindheit habe ich eine grosse Leidenschaft für Flugzeuge und die Luftfahrt. Dieses Projekt entstand aus dem Wunsch heraus, meine theoretischen Kenntnisse als Software-Engineering-Student (1. Jahr) in die Praxis umzusetzen und mich im Bereich Hard- und Softwareentwicklung weiterzubilden. Mein Ziel war es, von Grund auf ein funktionierendes Flugsystem zu bauen und das Zusammenspiel von Elektronik, Aerodynamik und Code zu verstehen.

Hardware & Materialien

Nach intensiver Recherche habe ich die folgenden Komponenten sorgfältig ausgewählt, um ein optimales Verhältnis von Gewicht, Leistung und Effizienz zu erreichen:

Flugwerk (Chassis): 5 mm Leichtschaumplatten (Foamboard). Um das Gerüst zu stabilisieren, ohne unnötiges Gewicht hinzuzufügen, habe ich leichte Carbonstäbe zur Verstärkung eingesetzt.

Mikrocontroller: 2x Arduino Nano (bewusst gewählt wegen ihres geringen Gewichts und der kompakten Bauform).

Motor: 1400KV Brushless Motor.

ESC (Regler): 30A Electronic Speed Controller.

Akku: 2400mAh LiPo (Lithium-Polymer) Akku.

Kommunikation: HC-12 Funkmodul (Transceiver).

Technische Herausforderungen & Lösungen

Da ich dieses Flugzeug komplett selbst entworfen und gebaut habe, stiess ich auf einige technische Hürden, die mir wertvolle Lektionen in der Fehlerbehebung (Troubleshooting) eingebracht haben:

Funkverbindung: Ursprünglich wollte ich das NRF24L01-Modul verwenden. Ich stellte jedoch fest, dass es sehr komplex einzurichten ist und für ein erstes Projekt viel Erfahrung erfordert. Um eine stabile und zuverlässige Verbindung zu gewährleisten, bin ich auf das HC-12-Modul umgestiegen, was sich als viel praktischer erwies.

Spannungsschwankungen & Signalverlust: Bei ersten Tests verhielt sich die Funksteuerung teilweise fehlerhaft. Ich fand heraus, dass dies an elektrischen Störungen und Spannungsabfällen lag, die durch den Motor verursacht wurden. Dieses Problem konnte ich erfolgreich lösen, indem ich einen 1000µF Elektrolytkondensator und einen 100nF Keramikkondensator in den Schaltkreis integrierte. Diese filtern die Spannungsspitzen, wodurch die Funkverbindung nun absolut stabil läuft.

Lernprozess & Danksagung

Da dies mein erstes Elektronik- und Luftfahrtprojekt ist, habe ich zur Orientierung und Fehlersuche verschiedene Online-Ressourcen, Foren und auch KI-Tools genutzt. Ich stehe noch am Anfang meiner Laufbahn als Ingenieur, aber die praktische Erfahrung, einen eigenen Schaltkreis zu entwerfen, die Steuerungslogik zu schreiben und reale Hardware-Probleme zu lösen, ist unglaublich wertvoll. Ich werde dieses Projekt kontinuierlich weiterentwickeln, während meine Kenntnisse in der Hard- und Softwareentwicklung wachsen.


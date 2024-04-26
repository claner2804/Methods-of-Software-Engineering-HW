Methoden der Spieleentwicklung V (100%)

Sie haben den letzte Woche implementierten Prototypen Ihres Spiels nun einer größeren Gruppe von Spieletester:innen zum Testen gegeben. Deren Feedback zeigte vor allem zwei Kritikpunkte auf: (1) Das Inventar ist viel zu klein, und (2) es kommt immer wieder zu Abstürzen, die wahrscheinlich von Memory Leaks verursacht werden. Daher haben Sie sich entschlossen, für den nächsten Prototpyen diese zwei Punkte anzugehen.

Unendliches Inventar

Ihre Spieletester:innen haben sich darüber beschwert, dass das Inventar zu beschränkt ist und sie viel zu viel Loot in den Dungeons zurücklassen müssen. Es wurde daher beschlossen, dass alle Charaktere nun ein unbegrenztes Inventar bekommen sollen (Die Ausrüstung der Heldin ist davon nicht betroffen). Dies soll durch die Verwendung eines geeigneten Datencontainers der Standardbibliothek umgesetzt werden. Schauen Sie sich die im Webinar genannten Container genauer an und wählen Sie einen passenden Container aus.
Damit der restliche Code möglichst unverändert weiterverwendet werden kann, soll die dazugehörige öffentliche Schnittstelle (die Funktionen addInventarItem(), removeInventarItem(), getInventory() und sellItem()) dabei nicht geändert werden (abgesehen von den Änderungen, die sich durch die weitere Aufgabenstellung unten ergeben). Es sollen weiterhin Exceptions geworfen werden, wenn auf einen ungültigen Slot zugegriffen wird.


Object Ownership

Charaktere und die Klasse Game

Ein weiterer Punkt, den die Spieletester:innen herausgefunden haben, ist, dass das Spiel nach einer längeren Spielzeit abstürzt, da wohl ein Memory Leak vorliegt. Aus diesen Grund soll die Frage der Object Ownership für die Charaktere und Gegenstände gelöst werden. Der Plan ist die Implementierung einer eigenen Klasse Game, der die Ownership über alle Charaktere übernimmt. Für die Charaktere sollen ab jetzt ausschließlich Heap-Objekte (also mit new erzeugte Objekte) zum Einsatz kommen. Diese sollen als Key-Value Paare gespeichert werden, wobei der Name des Charakters den Key bildet (ab jetzt müssen alle Charakternamen eindeutig sein).Schauen Sie sich die im Webinar genannten Container genauer an und wählen Sie einen passenden Container aus. Ob Sie Smart Pointer verwenden wollen, bleibt Ihnen überlassen.
Diese Klasse soll außerdem die Objektfunktion play()besitzen, die das eigentliche Spiel implementiert (Der Code, der vorher in der main()-Funktion zu finden war, wandert nun in diese Funktion).
Die Klasse Game soll auch sicherstellen, dass alle Charaktere, deren Lebenspunkte unter 0 sinken, von der Klasse Game direkt nach dem Looten zerstört werden. Damit sollte das Problem der Spieleabstürze gelöst sein. Spätestens im Destruktor von Game sollten alle noch lebenden Charaktere zerstört werden. Implementieren Sie entsprechende Debuggingausgaben in den Destruktoren aller Charaktere, damit Sie nachverfolgen können, dass am Ende auch tatsächlich alle Charaktere zerstört wurden.

Gegenstände

Auch für die Gegenstände muss die Ownership-Frage gestellt werden. Für Gegenstände, die sich im Iventar eines Charakters befinden, übernimmt der Charakter die Ownership. 
Zur Vereinfachung sollen für die Verwaltung der Gegenstände Smart Pointer verwendet werden. Damit soll sichergestellt werden, dass mittels Reference Counting Gegenstände automatisch zerstört werden, die nicht mehr benötigt werden. Dadurch ergeben sich folgende Änderungen:

Das Inventar bzw. das Array gear für die Ausrüstung speichert nun Objekte vom Typ std::shared_ptr<Item>.

Funktionen, die Gegenstände zurückgeben, haben nun als Rückgabewert einen Smart Pointer (z.B. std::shared_ptr<Item> getInventory(int index)).
	
Funktionen, die Gegenstände als Eingabeargument erwarten, bekommen nun einen Smart Pointer übergeben (z.B. int addInventarItem(std::shared_ptr<Item> item)).

Gegenstände, die sich nicht im Inventar eines Charakters befinden (z.B. verkaufte Gegenstände), brauchen auch einen Object Owner. In diesem Fall soll auch die Klasse Game die Object Ownership übernehmen. Wählen Sie wieder selbstständig einen passenden Datencontainer aus. Die Gegenstände brauchen kein eindeutig identifizierendes Merkmal.

Überprüfen Sie durch entsprechende Debuggingausgaben im Destruktor, ob die Gegenstände auch tatsächlich gelöscht werden.
			
			
Testprogramm

Implementieren Sie wieder ein Testprogramm, diesmal in der play() Methode, in dem die Heldin gegen zwei Feinde kämpft, den Zauberer Pascal und den Kämpfer Matthias. Am Ende der Kämpfe sollen wieder alle erbeuteten Gegenstände verkauft werden. In der main()-Funktion wird nur eine Instanz der Klasse Game als Stackobjekt erzeugt und dann die Methode play()aufgerufen.


![image](https://github.com/claner2804/Methods-of-Software-Engineering-HW5/assets/131294860/db707df7-a7f4-4d7d-b0aa-65fa70c0b026)

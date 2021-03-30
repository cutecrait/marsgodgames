[Lea ohne ae/ue/oe]
## Get Git
https://git-scm.com/download/win hier runterladen

## Git Befehle fur euer System

1. Neuen Ordner machen auf eurem System, hier rechts klick, Kontextmenu >> Git Bash here klicken
2. In der Konsole: `git clone https:// DEIN UDERNAME @bitbucket.org/CuteCrait/marsgodgames.git` und enter //paste in der konsole nur mit rechtsklick kontextmenu paste

---
Ab hier musst du die Git Bash in dem neuen Ordner MarsGodGames benutzten

3. `git status` gibt Status der files, ob staged fur commit oder nicht usw
4. `git add .` Addet alle veranderten Dateien zum commit ohne geloschte / `git add -A` commitet Loschungen mit
5. Wenn eure Anderungen gestaged sind fur den commit, konnt ihr sie mit `git commit -m"telling you what i changed here"` commiten 
	(jetzt sind die Anderungen auf eurem System gelogged, man konnte also nun eine Version zuruckspringen z.b)
6. `git push` ladt nun eure neuen commits auf den server hoch
7. falls server eine neuere version als ihr habt, musst ihr erst `git pull` ausfuhren
---
MERGECONFLICT: Projekt nochmal offnen und geanderten Code anschauen, bei merge conflikten steht dann z.b. 
```
	>>>>>>>> a5c3534 (ours) 
	var c = 1:
	========
	var c = 2:
	<<<<<<<< gh4hj324j1 (theirs)
```
hier muss man dann entscheiden was richtig ist und den rest dann rausloschen. 
Danach wieder adden und committe und dein commit zahlt jetzt, also wenn du es verkackt hast oder was ubersehen hast, hassen wir dich. 
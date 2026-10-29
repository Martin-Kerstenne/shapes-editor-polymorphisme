# Shapes – Hiérarchie de formes géométriques en C++

TP de programmation orientée objet (BUT Informatique, IUT Aix-Marseille) : implantation en C++ d'un arbre d'héritage de formes géométriques, affichées dans une fenêtre grâce à la mini-bibliothèque **EZDraw++**.

L'objectif est avant tout de mettre en pratique l'**héritage**, le **polymorphisme** et les **classes abstraites**.

## Architecture

| Classe | Rôle |
|---|---|
| `Point` | Point de l'écran, dessiné sous forme d'un petit carré (plein et rouge si actif, bord noir sinon) |
| `Shape` | Classe abstraite : ancre, remplissage (`filled`), épaisseur du tracé (`thickness`), sélection |
| `Rectangle` | Rectangle plein ou vide ; constructeur par copie à partir d'un `Square` |
| `Square` | Carré (dérive de `Shape`) |
| `Ellipse` | Ellipse pleine ou vide ; constructeur à partir d'un `Circle` |
| `Circle` | Cercle (dérive de `Shape`) |
| `SetOfShapes` | Ensemble de formes : dessin de l'ensemble, détection de la forme survolée (`isOver`, renvoie un pointeur ou `nullptr`) |

Chaque classe dérivée redéfinit :

- `draw(EZWindow&)` : dessin de la forme (pleine ou vide selon `filled`) ;
- `modifyAttributes()` : menu textuel sur la console pour consulter et modifier les attributs, chaque niveau d'héritage appelant celui de sa classe mère.

> Pendant la saisie dans la console, le traitement des événements est bloqué : la fenêtre ne se rafraîchit pas tant que l'utilisateur n'a pas validé sa réponse.

## Prérequis

- Un compilateur C++ (`g++`) et `make`
- La bibliothèque EZDraw++ (incluse dans le dépôt)

## Compilation et exécution

Tous les fichiers sources sont à la racine du dépôt.

```bash
make
```

Puis lancer l'exécutable généré. Des Makefiles pour Windows sont également fournis avec l'archive du TP.

## Structure du dépôt

```
.
├── Makefile
├── main.cpp
├── MyWindow.hpp / MyWindow.cpp
├── Point.hpp / Point.cpp
├── Shape.hpp / Shape.cpp
├── Rectangle.hpp / Rectangle.cpp
├── Square.hpp / Square.cpp
├── Ellipse.hpp / Ellipse.cpp
├── Circle.hpp / Circle.cpp
├── SetOfShapes.hpp / SetOfShapes.cpp
└── EZDraw++ (bibliothèque fournie)
```

## Notions mises en œuvre

- Héritage et classes abstraites (`Shape`)
- Méthodes virtuelles et polymorphisme
- Gestion d'une collection d'objets polymorphes via des pointeurs
- Initiation à la programmation d'interfaces graphiques avec EZDraw++

## Auteur

Martin Kerstenne – [martin-kerstenne.github.io](https://martin-kerstenne.github.io)

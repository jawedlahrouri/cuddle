[![Academic Year](https://img.shields.io/badge/Epitech-Tek1-blue?style=for-the-badge&logo=epitech&logoColor=white)](https://www.epitech.eu/)
[![Language: C](https://img.shields.io/badge/Language-C-00599C.svg?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Module](https://img.shields.io/badge/Module-B--CPE--200-informational?style=for-the-badge)](#)

# 🐼 Cuddle — C DataFrame & Tabular CSV Manipulation Library

**Cuddle** is a lightweight, high-performance data manipulation library written in C. Inspired by Python's **Pandas**, it provides a structured `dataframe_t` container to parse, inspect, filter, transform, sort, and export tabular CSV data with typed columns.

---

## 🚀 Fonctionnalités Clés

- **Gestion des Types de Données** : Typage automatique des colonnes via `column_type_t` (`BOOL`, `INT`, `UINT`, `FLOAT`, `STRING`, `UNDEFINED`).
- **Lecture & Écriture CSV** :
  - `df_read_csv(char *filename, char *separator)` : Chargement et parsing robuste de fichiers CSV.
  - `df_write_csv(dataframe_t *dataframe, const char *filename)` : Sérialisation et sauvegarde sur disque.
- **Inspection & Exploration** :
  - `df_head(df, nb_rows)` : Visualisation des $N$ premières lignes.
  - `df_tail(df, nb_rows)` : Visualisation des $N$ dernières lignes.
  - `df_shape(df)` : Récupération des dimensions (`nb_rows`, `nb_columns`).
  - `df_info(df)` : Affichage du résumé structurel (noms de colonnes, types, valeurs non nulles).
  - `df_describe(df)` : Statistiques descriptives sur les colonnes numériques.
- **Accès & Sélection de Données** :
  - `df_get_value(df, row, column)` : Extraction d'une cellule spécifique.
  - `df_get_values(df, column)` : Récupération d'un vecteur colonne complet.
  - `df_get_unique_values(df, column)` : Extraction des valeurs distinctes d'une colonne.
- **Opérations Fonctionnelles** :
  - `df_filter(df, column, filter_func)` : Filtrage des lignes via un prédicat booléen.
  - `df_sort(df, column, sort_func)` : Tri des lignes selon une fonction de comparaison.
  - `df_apply(df, column, apply_func)` : Application d'une transformation sur chaque élément d'une colonne.
- **Gestion Mémoire Sûre** :
  - `df_free(df)` : Libération propre de l'intégralité des buffers, types et cellules de données sans fuite.

---

## 🛠️ Structure de Données Principale

```c
typedef enum {
    BOOL, INT, UINT, FLOAT, STRING, UNDEFINED
} column_type_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
    char *separator;
} dataframe_t;
```

---

## 📦 Compilation & Intégration

Le projet se compile sous forme de bibliothèque statique :

```bash
make        # Génère la bibliothèque statique
make clean  # Nettoie les fichiers objets temporaires
make fclean # Supprime les binaires et bibliothèques
make re     # Recompile l'ensemble
```

---

## 💡 Exemple d'Utilisation

```c
#include "dataframe.h"

int main(void)
{
    // Chargement du DataFrame depuis un fichier CSV
    dataframe_t *df = df_read_csv("data.csv", ",");
    if (!df)
        return 84;

    // Affichage des informations et des 5 premières lignes
    df_info(df);
    dataframe_t *top5 = df_head(df, 5);
    df_describe(top5);

    // Libération mémoire
    df_free(top5);
    df_free(df);
    return 0;
}
```

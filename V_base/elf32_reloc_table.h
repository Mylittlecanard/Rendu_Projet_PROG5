#ifndef _LISTE_RELOC_TABLE_H_

#define _LISTE_RELOC_TABLE_H_

#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    Elf32_Shdr header;
    Elf32_Rela* tabrela;
    Elf32_Rel* tabrel;
} elf32_rela_table;

typedef struct {
    int size;
    int size_max;
    elf32_rela_table* table;
} elf32_section_reloc;

//elf32_rela_table
void creer_table(elf32_rela_table * t, int taille, int type);

int est_vide_table(elf32_rela_table t);

int taille_table(elf32_rela_table t);

void vider_table(elf32_rela_table * t);

void free_table(elf32_rela_table * t);

//elf32_section_rela
void creer_section(elf32_section_reloc * s, int taille);

int est_vide_section(elf32_section_reloc s);

int taille_section(elf32_section_reloc s);

void vider_section(elf32_section_reloc * s);

void re_alloc_section(elf32_section_reloc * s);

int ajouter_section(elf32_section_reloc * s, elf32_rela_table t);

int supprimer_section(elf32_section_reloc * s, int index);

void free_section(elf32_section_reloc *s);

#endif


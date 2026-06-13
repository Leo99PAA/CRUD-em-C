# Instrucoes para subir no GitHub

## Nome do repositorio

Crie o repositorio no GitHub com o nome:

```text
CRUD-em-C
```

O titulo/descricao pode ficar como:

```text
CRUD em C
```

Observacao: o GitHub normalmente usa nomes de repositorio sem espacos na URL.

## Branch

A branch local foi criada como:

```text
projeto-1-semestre
```

O nome solicitado, `projeto 1° semestre`, nao foi aceito pelo Git como nome valido de branch.

## Depois de criar o repositorio no GitHub

Troque `SEU_USUARIO` pelo seu usuario do GitHub:

```bash
git remote add origin https://github.com/SEU_USUARIO/CRUD-em-C.git
git push -u origin projeto-1-semestre
```

Se o remoto ja existir, use:

```bash
git remote set-url origin https://github.com/SEU_USUARIO/CRUD-em-C.git
git push -u origin projeto-1-semestre
```

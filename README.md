# compute the average BOO 

## Reference

The Eq. (5) in Paper: J. Chem. Phys. 129, 114707 (2008); https://doi.org/10.1063/1.2977970

## Install

Put the source file in lammps/src

## Usage

The new compute name is compute aveorientorder/atom.

One can add new keyword ave to use the new feature addding to the normal compute orientorder/atom.

E.g.

``
compute 1 all aveorientorder/atom degrees 2 4 6 ave
``

## Output

The new keyword ave will append qnm_l and qnm_l*, ql_ave to normal output.

/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef COMPUTE_CLASS
// clang-format off
ComputeStyle(aveorientorder/atom,ComputeOrientAveOrderAtom);
// clang-format on
#else

#ifndef LMP_COMPUTE_AVEORIENTORDER_ATOM_H
#define LMP_COMPUTE_AVEORIENTORDER_ATOM_H

#include "compute.h"

namespace LAMMPS_NS {

class ComputeOrientAveOrderAtom : public Compute {
 public:
  ComputeOrientAveOrderAtom(class LAMMPS *, int, char **);
  ~ComputeOrientAveOrderAtom() override;
  void init() override;
  void init_list(int, class NeighList *) override;
  void compute_peratom() override;
  double memory_usage() override;
  int pack_forward_comm(int, int *, double *, int, int *) override;
  void unpack_forward_comm(int, int, double *) override;
  double cutsq;
  int iqlcomp, qlcomp, qlcompflag, wlflag, wlhatflag, aveflag;
  int *qlist;
  int nqlist;

 protected:
  int nmax, maxneigh, ncol, nnn;
  int qnm_index; // start index of qnm in qn array
  int ave_qn_index; // start index of qnm in qn array
  class NeighList *list;
  double *distsq;
  int *nearest;
  double **rlist;
  int qmax;
  double **qnarray;
  //double **qnm_all; // BXU: array that store all qnm
  double **qnm_r;
  double **qnm_i;

  void select3(int, int, double *, int *, double **);
  void calc_boop(double **rlist, int numNeighbors, double qn[], int nlist[], int nnlist);

  double polar_prefactor(int, int, double);
  double associated_legendre(int, int, double);

  virtual void init_clebsch_gordan();
  double *cglist;    // Clebsch-Gordan coeffs
  int idxcg_max;
  int chunksize;
};

}    // namespace LAMMPS_NS

#endif
#endif

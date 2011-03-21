//Copyright 1999 President and Fellows of Harvard University
//archivesites.h

#ifndef _archivesites
#define _archivesites
#include "standard.h"
#include "seqset.h"
#include "motif.h"

class ArchiveSites{
  const Seqset& arch_seqset;
	vector<Motif> archive;
  double arch_sim_cutoff;
	double* pseudo;
  int arch_min_visits;

 public:
  ArchiveSites(Seqset& seq, double sim_cut, double* pseudo);
	int nmots() const { return archive.size(); }
  bool check_motif(const Motif& m);               // Returns true if no better motif, false otherwise
  bool consider_motif(const Motif& m);									// Returns true if motif was added, false otherwise
  Motif* return_best(const int i=0);
	void clear();
	void read(istream& archin);
	void write(ostream& archout);
};


#endif

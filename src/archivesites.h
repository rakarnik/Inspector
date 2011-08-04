#ifndef _archivesites
#define _archivesites
#include "seqset.h"
#include "bgmodel.h"
#include "motif.h"
#include "motifcompare.h"

class ArchiveSites{
	const Seqset& seqset;
	const MotifCompare mc;
	vector<Motif> archive;
	const double sim_cutoff;
	const vector<double>& pseudo;
	const vector<double>& backfreq;
	int min_visits;

public:
	ArchiveSites(const Seqset& seq, const BGModel& bgm, const double sim_cut, const vector<double>& p, const vector<double>& b);
	int nmots() const { return archive.size(); }
	vector<Motif>& get_archive() { return archive; }
	bool check_motif(const Motif& m);               // Returns true if no better motif, false otherwise
	bool consider_motif(const Motif& m);            // Returns true if motif was added, false otherwise
	Motif* return_best(const int i=0);
	void clear();
	void read(istream& archin);
	void write(ostream& archout);
};


#endif

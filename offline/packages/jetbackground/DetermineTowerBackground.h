#ifndef __DETERMINETOWERBACKGROUND_H__
#define __DETERMINETOWERBACKGROUND_H__

//===========================================================
/// \file DetermineTowerBackground.h
/// \brief UE background calculator
/// \author Dennis V. Perepelitsa
//===========================================================

// PHENIX includes
#include <fun4all/Fun4AllReturnCodes.h>
#include <fun4all/SubsysReco.h>
#include <phool/PHTimeServer.h>

// standard includes
#include <vector>

// forward declarations
class PHCompositeNode;

/// \class DetermineTowerBackground
///
/// \brief UE background calculator
///
/// This module constructs dE/deta vs. eta and v2 estimates given an
/// (unsubtracted) set of calorimeter towers and possible a set of
/// exclusion jets (seeds)
///
class DetermineTowerBackground : public SubsysReco
{
 public:
  DetermineTowerBackground(const std::string &name = "DetermineTowerBackground");
  virtual ~DetermineTowerBackground();

  int Init(PHCompositeNode *topNode);
  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);

  void SetBackgroundOutputName( std::string name );
  void SetSeedType( int seed_type );
  
 private:
  int CreateNode(PHCompositeNode *topNode);
  void FillNode(PHCompositeNode *topNode);

  float _v2[3];
  float _Psi2[3];
  std::vector< std::vector<float> > _UE;
  
  int _HCAL_NETA;
  int _HCAL_NPHI;

  std::vector<std::vector<float> > _EMCAL_E;
  std::vector<std::vector<float> > _IHCAL_E;
  std::vector<std::vector<float> > _OHCAL_E;

  std::string _backgroundName;

  int _seed_type;

  std::vector<float> _seed_eta;
  std::vector<float> _seed_phi;

};

#endif  // __DETERMINETOWERBACKGROUND_H__

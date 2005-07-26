#ifndef DIGIHCAL_HFDATAFRAME_H
#define DIGIHCAL_HFDATAFRAME_H

#include "DataFormats/HcalDetId/interface/HcalDetId.h"
#include "DataFormats/HcalDetId/interface/HcalElectronicsId.h"
#include "DataFormats/HcalDigi/interface/HcalQIESample.h"
#include <vector>
#include <ostream>

namespace cms {

  class HFDataFrame {
  public:
    HFDataFrame(); // for persistence
    explicit HFDataFrame(const HcalDetId& id);
    
    const HcalDetId& id() const { return id_; }
    const HcalElectronicsId& elecId() const { return electronicsId_; }
    
    int size() const { return size_; }
    int presamples() const { return hcalPresamples_; }
    
    const HcalQIESample& operator[](int i) const { return data_[i]; }
    const HcalQIESample& sample(int i) const { return data_[i]; }
    
    void setSize(int size);
    void setPresamples(int ps);
    void setSample(int i, const HcalQIESample& sam) { data_[i]=sam; }
    void setReadoutIds(const HcalElectronicsId& eid);
    
    static const int MAXSAMPLES = 10;
  private:
    cms::HcalDetId id_;
    cms::HcalElectronicsId electronicsId_; 
    int size_;
    int hcalPresamples_;
    std::vector<cms::HcalQIESample> data_;
  };

  std::ostream& operator<<(std::ostream&, const HFDataFrame&);

}




#endif

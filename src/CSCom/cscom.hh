#ifndef __INC_MVDS_CSCOM_HH__
#define __INC_MVDS_CSCOM_HH__

namespace mvds {


  /**
   *
   *
   */
  class CSCom {

    void copy(CSCom const &other);
    void destroy();

  public:

    CSCom();

    ~CSCom();

    CSCom(CSCom const &other);

    CSCom &operator=(CSCom const &other);


    // Add your public member functions here...


  private:

    // Add your private members...

  };

  inline CSCom::~CSCom()
  {
    destroy();
  }

  inline CSCom CSCom::CSCom(CSCom const &other)
  {
    copy(other);
  }

  inline CSCom &CSCom::operator=(CSCom const &other)
  {
    if (this != &other) {
      destroy();
      copy(other);
    }
    return *this;
  }


};


#endif // __INC_MVDS_CSCOM_HH__


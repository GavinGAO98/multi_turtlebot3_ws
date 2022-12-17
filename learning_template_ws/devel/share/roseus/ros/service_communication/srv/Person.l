;; Auto-generated. Do not edit!


(when (boundp 'service_communication::Person)
  (if (not (find-package "SERVICE_COMMUNICATION"))
    (make-package "SERVICE_COMMUNICATION"))
  (shadow 'Person (find-package "SERVICE_COMMUNICATION")))
(unless (find-package "SERVICE_COMMUNICATION::PERSON")
  (make-package "SERVICE_COMMUNICATION::PERSON"))
(unless (find-package "SERVICE_COMMUNICATION::PERSONREQUEST")
  (make-package "SERVICE_COMMUNICATION::PERSONREQUEST"))
(unless (find-package "SERVICE_COMMUNICATION::PERSONRESPONSE")
  (make-package "SERVICE_COMMUNICATION::PERSONRESPONSE"))

(in-package "ROS")





(intern "*UNKNOWN*" (find-package "SERVICE_COMMUNICATION::PERSONREQUEST"))
(shadow '*UNKNOWN* (find-package "SERVICE_COMMUNICATION::PERSONREQUEST"))
(defconstant service_communication::PersonRequest::*UNKNOWN* 0)
(intern "*MALE*" (find-package "SERVICE_COMMUNICATION::PERSONREQUEST"))
(shadow '*MALE* (find-package "SERVICE_COMMUNICATION::PERSONREQUEST"))
(defconstant service_communication::PersonRequest::*MALE* 1)
(intern "*FEMALE*" (find-package "SERVICE_COMMUNICATION::PERSONREQUEST"))
(shadow '*FEMALE* (find-package "SERVICE_COMMUNICATION::PERSONREQUEST"))
(defconstant service_communication::PersonRequest::*FEMALE* 2)
(defclass service_communication::PersonRequest
  :super ros::object
  :slots (_name _age _sex ))

(defmethod service_communication::PersonRequest
  (:init
   (&key
    ((:name __name) "")
    ((:age __age) 0)
    ((:sex __sex) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _age (round __age))
   (setq _sex (round __sex))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:sex
   (&optional __sex)
   (if __sex (setq _sex __sex)) _sex)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint8 _age
    1
    ;; uint8 _sex
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _age
       (write-byte _age s)
     ;; uint8 _sex
       (write-byte _sex s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _sex
     (setq _sex (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass service_communication::PersonResponse
  :super ros::object
  :slots (_result ))

(defmethod service_communication::PersonResponse
  (:init
   (&key
    ((:result __result) "")
    )
   (send-super :init)
   (setq _result (string __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; string _result
    4 (length _result)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _result
       (write-long (length _result) s) (princ _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _result
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _result (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass service_communication::Person
  :super ros::object
  :slots ())

(setf (get service_communication::Person :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get service_communication::Person :datatype-) "service_communication/Person")
(setf (get service_communication::Person :request) service_communication::PersonRequest)
(setf (get service_communication::Person :response) service_communication::PersonResponse)

(defmethod service_communication::PersonRequest
  (:response () (instance service_communication::PersonResponse :init)))

(setf (get service_communication::PersonRequest :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get service_communication::PersonRequest :datatype-) "service_communication/PersonRequest")
(setf (get service_communication::PersonRequest :definition-)
      "string name
uint8  age
uint8  sex

uint8 unknown = 0
uint8 male    = 1
uint8 female  = 2

---
string result

")

(setf (get service_communication::PersonResponse :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get service_communication::PersonResponse :datatype-) "service_communication/PersonResponse")
(setf (get service_communication::PersonResponse :definition-)
      "string name
uint8  age
uint8  sex

uint8 unknown = 0
uint8 male    = 1
uint8 female  = 2

---
string result

")



(provide :service_communication/Person "c198113e7dd9cc5c9fd5f271c8479b39")



/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

#ifndef __qSlicerTrackerStabilizerModuleWidget_h
#define __qSlicerTrackerStabilizerModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerTrackerStabilizerModuleExport.h"

class qSlicerTrackerStabilizerModuleWidgetPrivate;
class vtkMRMLNode;
class vtkMRMLScene;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_TRACKERSTABILIZER_EXPORT qSlicerTrackerStabilizerModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerTrackerStabilizerModuleWidget(QWidget *parent=0);
  virtual ~qSlicerTrackerStabilizerModuleWidget();

public slots:

  virtual void setMRMLScene( vtkMRMLScene* scene );
  void onSceneImportedEvent();

protected slots:

  void onModuleNodeChanged();

  void onUpdatingTransformTimeout();
  void onFilterToggled(bool filter);
  void onInputNodeChanged();
  void onOutputNodeChanged();
  void onCutOffFrequencyChanged(double cutoff);
  void UpdateFromMRMLNode();

protected:
  QScopedPointer<qSlicerTrackerStabilizerModuleWidgetPrivate> d_ptr;

  virtual void setup();
  virtual void enter();

private:
  Q_DECLARE_PRIVATE(qSlicerTrackerStabilizerModuleWidget);
  Q_DISABLE_COPY(qSlicerTrackerStabilizerModuleWidget);
};

#endif

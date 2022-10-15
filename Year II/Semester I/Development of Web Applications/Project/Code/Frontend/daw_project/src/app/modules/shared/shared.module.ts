import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { AddEditClientComponent } from './add-edit-client/add-edit-client.component';
import { MaterialModule } from '../material/material.module';
import { ReactiveFormsModule } from '@angular/forms';
import { HoverButtonDirective } from 'src/app/hover-button.directive';
import { AddEditEmployeeComponent } from './add-edit-employee/add-edit-employee.component';
import { MarksPipe } from 'src/app/marks.pipe';
import { AddEditPcPartComponent } from './add-edit-pc-part/add-edit-pc-part.component';



@NgModule({
  declarations: [
    AddEditClientComponent,
    AddEditEmployeeComponent,
    AddEditPcPartComponent,
    HoverButtonDirective,
    MarksPipe,
  ],
  imports: [
    CommonModule,
    MaterialModule,
    ReactiveFormsModule
  ],
  entryComponents: [
    AddEditClientComponent
  ],
  exports: [
    HoverButtonDirective,
    MarksPipe
  ]
})
export class SharedModule { }

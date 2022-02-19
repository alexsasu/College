import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { EmployeesComponent } from './employees/employees.component';
import { EmployeesRoutingModule } from './employees-routing.module';
import { MaterialModule } from '../material/material.module';
import { SharedModule } from '../shared/shared.module';
import { EmployeeComponent } from './employee/employee.component';
// import { EmployeeComponent } from './employee/employee.component';
// import { MarksPipe } from 'src/app/marks.pipe';

@NgModule({
  declarations: [
    EmployeesComponent,
    EmployeeComponent,
    // EmployeeComponent,
    // MarksPipe
  ],
  imports: [
    CommonModule,
    EmployeesRoutingModule,
    MaterialModule,
    SharedModule
  ],
  exports: [
    // MarksPipe
  ]
})
export class EmployeesModule { }

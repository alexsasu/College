import { Component, Inject, Injectable, OnInit } from '@angular/core';
import { AbstractControl, FormArray, FormControl, FormGroup } from '@angular/forms';
import { MatDialogRef, MAT_DIALOG_DATA } from '@angular/material/dialog';
import { EmployeesService } from 'src/app/services/employees.service';

@Component({
  selector: 'app-add-edit-employee',
  templateUrl: './add-edit-employee.component.html',
  styleUrls: ['./add-edit-employee.component.scss']
})
export class AddEditEmployeeComponent implements OnInit {

  public employeeForm: FormGroup = new FormGroup({
    employeeId: new FormControl(null),
    role: new FormControl(''),
    employeeLastName: new FormControl(''),
    employeeFirstName: new FormControl(''),
    salary: new FormControl(null),
    phoneNumber: new FormControl('')
  });
  public title: any;

  constructor(
    @Inject(MAT_DIALOG_DATA) public data: any,
    private employeesService: EmployeesService,
    public dialogRef: MatDialogRef<AddEditEmployeeComponent>
  ) { 
    console.log(this.data);
    if (data.employee) {
      this.title = 'Edit Employee';
      this.employeeForm.patchValue(this.data.employee);
    } else {
      this.title = 'Add Employee';
    }
  }

  get employeeId(): AbstractControl {
    return this.employeeForm?.get('employeeId') as AbstractControl;
  }
  get role(): AbstractControl {
    return this.employeeForm?.get('role') as AbstractControl;
  }
  get employeeLastName(): AbstractControl {
    return this.employeeForm?.get('employeeLastName') as AbstractControl;
  }
  get employeeFirstName(): AbstractControl {
    return this.employeeForm?.get('employeeFirstName') as AbstractControl;
  }
  get salary(): AbstractControl {
    return this.employeeForm?.get('salary') as AbstractControl;
  }
  get phoneNumber(): AbstractControl {
    return this.employeeForm?.get('phoneNumber') as AbstractControl;
  }

  ngOnInit(): void {
  }

  public addEmployee(): void {
    this.employeesService.addEmployee(this.employeeForm.value).subscribe({
      next: (result) => {
        this.dialogRef.close(result);
      },
      error: (e) => console.error(e)
    });
  }

  public editEmployee(): void {
    this.employeesService.editEmployee(this.employeeForm.value).subscribe({
      next: (result) => {
        this.dialogRef.close(result);
      },
      error: (e) => console.error(e)
    });
  }

}

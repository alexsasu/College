import { Component, Inject, Injectable, OnInit } from '@angular/core';
import { AbstractControl, FormArray, FormControl, FormGroup } from '@angular/forms';
import { MatDialogRef, MAT_DIALOG_DATA } from '@angular/material/dialog';
import { ClientsService } from 'src/app/services/clients.service';

@Component({
  selector: 'app-add-edit-client',
  templateUrl: './add-edit-client.component.html',
  styleUrls: ['./add-edit-client.component.scss']
})
export class AddEditClientComponent implements OnInit {

  public clientForm: FormGroup = new FormGroup({
    clientId: new FormControl(null),
    clientLastName: new FormControl(''),
    clientFirstName: new FormControl(''),
    deliveryAddressId: new FormControl(null),
    country: new FormControl(''),
    city: new FormControl(''),
    street: new FormControl(''),
    streetNumber: new FormControl(null)
  });
  public title: any;

  constructor(
    @Inject(MAT_DIALOG_DATA) public data: any,
    private clientsService: ClientsService,
    public dialogRef: MatDialogRef<AddEditClientComponent>
  ) { 
    console.log(this.data);
    if (data.client) {
      this.title = 'Edit Client';
      this.clientForm.patchValue(this.data.client);
    } else {
      this.title = 'Add Client';
    }
  }

  get clientId(): AbstractControl {
    return this.clientForm?.get('clientId') as AbstractControl;
  }
  get clientLastName(): AbstractControl {
    return this.clientForm?.get('clientLastName') as AbstractControl;
  }
  get clientFirstName(): AbstractControl {
    return this.clientForm?.get('clientFirstName') as AbstractControl;
  }
  get deliveryAddressId(): AbstractControl {
    return this.clientForm?.get('deliveryAddressId') as AbstractControl;
  }
  get country(): AbstractControl {
    return this.clientForm?.get('country') as AbstractControl;
  }
  get city(): AbstractControl {
    return this.clientForm?.get('city') as AbstractControl;
  }
  get street(): AbstractControl {
    return this.clientForm?.get('street') as AbstractControl;
  }
  get streetNumber(): AbstractControl {
    return this.clientForm?.get('streetNumber') as AbstractControl;
  }

  ngOnInit(): void {
  }

  public addClient(): void {
    this.clientsService.addClient(this.clientForm.value).subscribe({
      next: (result) => {
        this.dialogRef.close(result);
      },
      error: (e) => console.error(e)
    });
  }

  public editClient(): void {
    this.clientsService.editClient(this.clientForm.value).subscribe({
      next: (result) => {
        this.dialogRef.close(result);
      },
      error: (e) => console.error(e)
    });
  }

}

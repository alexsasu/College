import { Component, OnDestroy, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { DataService } from 'src/app/services/data.service';
import { Subscription } from 'rxjs';
import { ClientsService } from 'src/app/services/clients.service';
import { MatDialog, MatDialogConfig, MatDialogModule } from '@angular/material/dialog';
import { AddEditClientComponent } from '../../shared/add-edit-client/add-edit-client.component';
import { Client } from 'src/app/interfaces/client';
// import { User } from 'src/app/interfaces/user';

@Component({
  selector: 'app-clients',
  templateUrl: './clients.component.html',
  styleUrls: ['./clients.component.scss']
})
export class ClientsComponent implements OnInit, OnDestroy {

  // public subscription!: Subscription;
  // public loggedUser!: User;
  public parentMessage = 'Message from clients parent.';
  public clients: Client[] = [];
  public displayedColumns = ['clientId', 'clientLastName', 'clientFirstName', 'deliveryAddressId', 'country', 'city', 'street', 'streetNumber', 'profile', 'edit', 'delete'];

  constructor(
    private router: Router,
    private dataService: DataService,
    private clientsService: ClientsService,
    public dialog: MatDialog
  ) { }

  ngOnInit() {
    // this.subscription = this.dataService.currentUser.subscribe((user: User) => this.loggedUser = user);
    this.clientsService.getAllClientsWithTheirDeliveryAddress().subscribe({
      next: (result: Client[]) => {
        console.log(result);
        this.clients = result;
      },
      error: (e) => console.error(e)
    });
  }

  ngOnDestroy() {
    // this.subscription.unsubscribe();
  }

  public logout(): void {
    this.router.navigate(['/auth/login']);
  }

  public receiveMessage(event: any): void {
    console.log(event);
  }

  public openModal(client?: Client): void {
    const data = {
      client
    };
    const dialogConfig = new MatDialogConfig();
    dialogConfig.width = '550px';
    dialogConfig.height = '700px';
    dialogConfig.data = data;
    const dialogRef = this.dialog.open(AddEditClientComponent, dialogConfig);
    dialogRef.afterClosed().subscribe((result) => {
      console.log(result);
      if (result) {
        this.clientsService.getAllClientsWithTheirDeliveryAddress().subscribe({
          next: (result: Client[]) => {
            console.log(result);
            this.clients = result;
          },
          error: (e) => console.error(e)
        });
      }
    });
  }

  public viewClientProfile(id: number): void {
    // console.log(id);
    this.router.navigate(['/clients/client', id]);
  }

  public addNewClient(): void {
    this.openModal();
  }

  public editClient(client: Client): void {
    this.openModal(client);
  }

  public deleteClient(id: number): void {
    this.clientsService.deleteClient(id).subscribe({
      next: (result) => {
        // console.log(result);
        this.clientsService.getAllClientsWithTheirDeliveryAddress().subscribe({
          next: (result: Client[]) => {
            console.log(result);
            this.clients = result;
          },
          error: (e) => console.error(e)
        });
      },
      error: (e) => console.error
    });
  }

}
